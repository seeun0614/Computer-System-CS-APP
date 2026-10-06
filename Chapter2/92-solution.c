#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate (float_bits f) {
    float_bits is_NaN = ((f & (0xff000000u >> 1)) == (0xff000000u >> 1)) && !!(f & 0x7fffff);
    if (is_NaN) {
        printf("invoke is_NaN\n");
        return f;
    }
    else {
        float_bits sign = f >> 31;
        if (sign == 1u) {
            return f & 0x7fffffff;
        }
        else {
            return f | 0x80000000;
        }
    }
}

int main () {
    printf("%u", float_negate(0x12345678));
}