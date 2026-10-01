#include <stdio.h>

int any_odd_one (unsigned x) {
    int is_odd = !!(x & 0xAAAAAAAA);
    return is_odd;
}

int main(){
    unsigned x = 0x55555558;
    printf("%d", any_odd_one(x));
}