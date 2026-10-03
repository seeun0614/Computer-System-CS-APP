#include <stdio.h>

int fits_bits(int x, int n) {
    int tmp = 1 << (sizeof(int) << 3 -1);
    int is_positive = !(x & tmp) ;
    int possible_positive = is_positive && !(x >> n-1);
    int possible_negative = !is_positive && !(~(x >> n-1));
    return possible_negative | possible_positive;

}

int main () {
    printf("fits_bits(-2, 1) = %d (Expected: 0)\n", fits_bits(-2, 1));
    printf("fits_bits(-2, 2) = %d (Expected: 1)\n", fits_bits(-2, 2));
    printf("fits_bits(5, 3)  = %d (Expected: 0)\n", fits_bits(5, 3));
    printf("fits_bits(5, 4)  = %d (Expected: 1)\n", fits_bits(5, 4));
    return 0;
}