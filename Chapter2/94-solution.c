#include <stdio.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_twice (float_bits f) {
    float_bits is_NaN = ((f & (0xff000000u >> 1)) == (0xff000000u >> 1)) && !!(f & 0x7fffff);
    float_bits f_exp = f >> 23 & 0xFF;
    float_bits f_frac = f & 0x7FFFFF;
    float_bits f_sign = f & 0x80000000;
    if (is_NaN) {
        return f;
    }
    else {
        if (f_exp == 0xFF || f_exp == 0xFE) {
            printf("Inf\n");
            return f_sign | 0x7f800000;
        }
        else if (f_exp == 0x00) {
            printf("Denormalized\n");
            f_frac <<= 1;
            return f_sign | f_frac;
        }
        else {
            float_bits f_exp_mul2 = f_exp + 1;
            return f_sign | (f_exp_mul2 << 23) | f_frac;
        }
    }
}

int main () {
    float_bits n = float_twice(0x47400000);
    printf("%.8x\n",n);
    float f;
    memcpy(&f, &n, sizeof(float_bits));
    printf("%f",f);


}