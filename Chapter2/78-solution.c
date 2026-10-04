#include <stdio.h>

int divide_power2(int x, int k) {
    int is_x_negative = (x >> ((sizeof(int) * 8) -1));
    int div_x = (x + (is_x_negative & ((1<<k)-1))) >> k;
    return div_x;
}

int main () {
    printf("%d",divide_power2(12340,8));
}