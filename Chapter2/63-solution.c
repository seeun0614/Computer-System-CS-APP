#include <stdio.h>

//implement logical right shift
unsigned srl (unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    xsra = xsra & ((0x7fffffff >> k << 1) | 0x01);
    return xsra;
}
