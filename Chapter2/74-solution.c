#include <stdio.h>

int tsub_ok (int x, int y) {
    int is_x_positive = !(x & (-1 << ((sizeof(int) << 3) -1)));
    int is_y_positive = !(y & (-1 << ((sizeof(int) << 3) -1)));

    int is_overflow_possible = !!(is_x_positive ^ is_y_positive); //is_x_positive != is_y_positive => is_overflow_possible = 1
    int is_sub_positive = !((x-y) & (-1 << ((sizeof(int) << 3) -1)));
    int is_overflow = is_overflow_possible && (is_x_positive != is_sub_positive); 

    return !is_overflow;
}

int main () {
    printf("%d",tsub_ok(0xffffffff, 0x80000000));
    printf("%d",tsub_ok(0x00000001, 0x7fffffff));
    printf("%d",tsub_ok(0x00000000, 0x7fffffff));
}