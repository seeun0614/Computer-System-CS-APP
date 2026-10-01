#include <stdio.h>

//implement logical right shift
unsigned sra (unsigned x, int k) {
    unsigned xsrl = (int) x >> k;
    xsrl = xsrl & (~(0xffffffff << 8*sizeof(int) - k));
    return xsrl;
}

int main () {
    printf("%.2x",srl(0xffffffff, 4) );
}
