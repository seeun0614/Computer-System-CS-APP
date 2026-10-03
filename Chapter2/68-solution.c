#include <stdio.h>

int lower_one_mask (int n) {
    unsigned x = -1;
    int is_32 = !(sizeof(int)*8 -n);
    x = ~ ((x*!is_32) << (n*!is_32)); //0<=n<=31
    return (int)x;
}

int main (){
    printf("%.8x",lower_one_mask(32));
}