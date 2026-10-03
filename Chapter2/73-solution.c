#include <stdio.h>

int saturationg_add (int x, int y) {
    int is_x_positive = !(x & (-1 << ((sizeof(int) << 3) -1)));
    int is_y_positive = !(y & (-1 << ((sizeof(int) << 3) -1)));
    int is_overflow_possible = !(is_x_positive ^ is_y_positive); //is_x_negative == is_y_negative => is_overflow_possible = 1

    int TMin = -1 << ((sizeof(int) << 3) -1);

    int add_ = x + y;
    int is_add_positive = !(add_ & (-1 << ((sizeof(int) << 3) -1)));
    // printf ("is_add_positive = %d\n", is_add_positive);
    int is_overflow = is_overflow_possible && (is_add_positive != is_x_positive);
    // printf ("is_overflow = %d\n", is_overflow);
    int is_TMax = (-is_overflow) & (-is_x_positive) & ~TMin;
    // printf ("is_TMax = %d\n", is_TMax);
    int is_TMin = (-is_overflow) & (-!(is_x_positive)) & TMin;
    int add = (add_ * !is_overflow) | (is_TMax | is_TMin);
    return add;
}

int main () {
    printf("%.8x\n",saturationg_add(0x8fffe726, 0x83725377));
}