#include <stdio.h>

typedef unsigned float_bits;

float_bits float_absval (float_bits f) {
    float_bits is_NaN = ((f & (0xff000000u >> 1)) == (0xff000000u >> 1)) && !!(f & 0x7fffff);

    if (is_NaN) {
        return f;
    }
    else {
        return f & 0x7fffffff;
    }
}

int main () {

}