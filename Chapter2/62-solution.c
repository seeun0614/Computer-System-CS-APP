#include <stdio.h>

int int_shifts_are_arithmetic() {
    int x = 0xf0000000;
    x = x>>28;
    return !(~x);
}


int main()
{
    printf("%d",int_shifts_are_arithmetic());
}
