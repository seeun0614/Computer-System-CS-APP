#include <stdio.h>

int main () {
    int j = 5,k = 2;
    int a = 0xffffffff;
    a = a << k;
    int b = ~(a << j) & (0xffffffff << j);
    printf("a = %.8x\n", a);
    printf("b = %.8x", b);
}