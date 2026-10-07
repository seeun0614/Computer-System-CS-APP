#include <stdio.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_half (float_bits f) {
    float_bits is_NaN = ((f & (0xff000000u >> 1)) == (0xff000000u >> 1)) && !!(f & 0x7fffff);
    float_bits f_exp = f >> 23 & 0xFF;
    float_bits f_frac = f & 0x7FFFFF;
    float_bits f_sign = f & 0x80000000;
    if (is_NaN) {
        return f;
    }
    else {
        if (f_exp == 0xFF) {
            printf("Inf\n");
            return f_sign | 0x7f800000;
        }
        else if (f_exp == 0x00) {
            printf("Denormalized\n");
            if (f_frac & 0x000003 == 0x000003) {
                f_frac >>= 1;
                f_frac++;
                return f_sign | f_frac;
            }
            else {
                f_frac >>= 1;
                return f_sign | f_frac;
            }
            
        }
        else {
            if (f_exp == 0x01) {
                if ((f_frac & 0x000003) == 0x000003) {
                    f_frac = (f_frac >> 1) | 0x400000;
                    f_frac++;
                    return f_frac != 0x7FFFFF ?  f_sign | f_frac : f_sign | 0x800000;
                }
                else {
                    f_frac = (f_frac >> 1) | 0x400000;
                    f_exp = 0;
                    return f_sign | (f_exp << 23) | f_frac;
                }
            }
            else {
                float_bits f_exp_mul2 = f_exp - 1;
                return f_sign | (f_exp_mul2 << 23) | f_frac;
            }
            
        }
    }
}

int main () {
    float_bits n1 = 0x00ffffff;
    float_bits n2 = float_half(n1);
    float f1, f2;
    memcpy(&f1, &n1, sizeof(float_bits));
    memcpy(&f2, &n2, sizeof(float_bits));

    printf("f1: %f\nf2: %f",f1,f2);
}