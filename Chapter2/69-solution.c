#include <stdio.h>

unsigned rotate_left (unsigned x, int n) {
    int shift_ = !!n * (sizeof(int)*8 -n);
    unsigned rotate_bits = ((x & (~(0u) << shift_)) >> shift_) * !!n;
    x = (x << n) | rotate_bits;
    return x;
}

int main () {
    printf("%.8x",rotate_left(0x12345678, 8));
}