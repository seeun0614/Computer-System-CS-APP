#include <stdio.h>

int odd_ones (unsigned x) { //0x12 34 56 78
    unsigned first_div = x ^ (x>>16);
    unsigned second_div = first_div ^ (first_div >> 8);
    unsigned third_div = second_div ^ (second_div >> 4); // 0xk0000000
    unsigned fourth_div = third_div ^ (third_div >> 2);
    unsigned fifth_div = fourth_div ^ (fourth_div >> 1);
    fifth_div = fifth_div & 0x00000001;
    int is_odd = !!(fifth_div);
    return is_odd;
}

int main () {
    printf("%d", odd_ones(0xf0f0f0fe));
}