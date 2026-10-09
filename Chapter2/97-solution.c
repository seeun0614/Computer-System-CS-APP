#include <stdio.h>

typedef unsigned float_bits;

float_bits float_i2f (int i) {
    float_bits f_sign = i & 0x80000000;
    if (i == 0) return 0;
    else if (i == 0x80000000) {
        float_bits f_exp = 158 << 23;
        return f_exp | f_sign;
    }
    else if (i < 0) i = -i;

    float_bits f_E = 0;
    while (f_E < 30) {
        if ((1u << f_E) <= i && i < (1u << (f_E + 1))) {
            break;
        }
        else f_E++;
    }
    float_bits f_frac; //needs rounding?
    float_bits f_exp = (f_E + 127) << 23;
    if (f_E <= 23) {
        f_frac = (i - (1<<f_E)) << (23-f_E);
    }
    else {
        f_frac = (i - (1<<f_E));
        float_bits rounding_frac = f_frac & (0xffffffff >> (32-(f_E-23)));
        float_bits needs_rounding = !!(f_frac & (1 << (f_E-23))); //round되지 않는 frac bit 중 가장 작은값. 즉 fraction 끝 비트가 1로 끝나는 경우.

        if (needs_rounding) {
            if (!!(rounding_frac & (1 << (f_E-23-1)))) { // round 되는 frac bit 중 가장 큰 값이 1일때.
                if ((f_frac >> (f_E-23)) == 0x7fffff) { // frac이 올림시 exp++이 되는 경우.
                    f_frac = 0;
                    f_exp += 1u << 23;
                }
                else f_frac = (f_frac >> (f_E-23)) + 1; // 올림 발생.
            }
            else {
                f_frac = (f_frac >> (f_E-23)); // 버림 발생.
            }
        }
        else {
            if (!!(rounding_frac & (1 << (f_E-23-1)))) { // round 되는 frac bit 중 가장 큰 값이 1일때.
                if ((f_frac >> (f_E-23)) == 0x7fffff) { // frac이 올림시 exp++이 되는 경우.
                    f_frac = 0;
                    f_exp += 1u << 23;
                }
                else if (rounding_frac == (0x80000000 >> (32-(f_E-23)))) {
                    f_frac = (f_frac >> (f_E-23)); // 버림 발생.
                }
                else f_frac = (f_frac >> (f_E-23)) + 1; // 올림 발생.
            }
            else {
                f_frac = (f_frac >> (f_E-23)); // 버림 발생.
            }
        }
    }
    return f_sign| f_exp | f_frac;
    
}

int main () {

}