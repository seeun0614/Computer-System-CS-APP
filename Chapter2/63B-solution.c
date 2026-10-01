#include <stdio.h>

//implement arithmetic right shift
unsigned srl (unsigned x, int k) {
    unsigned int is_MSBit_1 = !!(x & 0x80000000); //0x00000001 or 0x00000000
    int w = 8*sizeof(int);
    unsigned int is_k_zero = !k; 
    unsigned int is_arithmetic = is_MSBit_1 * (0xffffffff) * (!is_k_zero); // 0xffffffff or 0x00000000
    unsigned xsra = (int) x >> k;
    xsra = xsra | (is_arithmetic << ((w - k) * !is_k_zero)); //0x00000001 -> xsra | (0xffffffff << w-k), 0x00000000 -> xsra | (0x00000000 << w-k)
    
    return xsra;
}

int main () {
    
}