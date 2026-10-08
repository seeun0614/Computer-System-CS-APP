#include <stdio.h>
#include <string.h>

typedef unsigned float_bits;

int float_f2i (float_bits f) {
    float_bits is_NaN = ((f & (0xff000000u >> 1)) == (0xff000000u >> 1)) && !!(f & 0x7fffff);
    float_bits f_exp = (f >> 23) & 0xFF;
    float_bits f_frac = f & 0x7FFFFF;
    int f_E = (int)f_exp - 127;
    float_bits f_sign = !(f & 0x80000000);
    int f2i;

    if (is_NaN) return 0x80000000;

    else if (f_sign == 1) { // f is positive
        if (f_E > 30) {
            return 0x80000000;
        }
        else if (f_E >= 0 && f_E <= 30) {
            f_frac = f_E <= 23 ? (f_frac >> (23-f_E)) : 0;
            f2i = (1 << f_E) + f_frac;
            return f2i;
        }
        else {
            return 0;
        }
    }
    else {
        if (f_E > 31) {
            return 0x80000000;
        }
        else if (f_E == 31) {
            if (f_frac == 0) {
                return 0x80000000;
            }
            else {
                return 0x80000000;
            }
        }
        else if (f_E >= 0 && f_E <= 30) {
            f_frac = f_E <= 23 ? (f_frac >> (23-f_E)) : 0;
            f2i = (1 << f_E) + f_frac;
            return -f2i;
        }
        else {
            return 0;
        }
    }
}

int main () {
    float_bits n1 = 0xBf10ffff; //0x3f800000 = 1, 
    int n2 = float_f2i(n1);
    float f1;
    memcpy(&f1, &n1, sizeof(float_bits));
    printf("f: %f\nn: %d",f1,n2);
}