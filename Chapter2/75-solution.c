#include <stdio.h>

int signed_high_prod (int x, int y); //assume this function has been implemented.

unsigned unsigned_high_prod (unsigned x, unsigned y) {
    int w = (sizeof(int) << 3);
    int int_x = (int) x;
    int int_y = (int) y;
    int x_w_sub_1 = !!(int_x >> (w -1));
    int y_w_sub_1 = !!(int_y >> (w -1));
    int Thigh = signed_high_prod (int_x, int_y);
    unsigned Uhigh = (unsigned)Thigh + (unsigned)x_w_sub_1 * (unsigned)y + (unsigned)y_w_sub_1 * (unsigned)x;
    return Uhigh;
}

int main () {
    
}