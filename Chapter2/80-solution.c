#include <stdio.h>

int divide_threefourts(int x, int k) {
    int is_x_negative = (x >> ((sizeof(int) * 8) -1));
    // int div_x = (x + (~is_x_negative & ((1<<k)-1))) >> k; x= TMax인 경우 TMax + 3 overflow 발생.
    int div_x = (x >> k) + (~is_x_negative & !!(x & ((1 << k) - 1))); //나머지가 있을때만 보정값 1을 더함.
    return div_x;
}

int threefourts (int x) {
    int mul_3_div_4 = x - divide_threefourts(x,2); // ((x << 2) - x) / 4
    return mul_3_div_4;
}

void main () {
    printf("%d",threefourts(501));
}