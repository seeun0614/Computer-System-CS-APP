#include <stdio.h>

//Q)A. In what way does our code fail to comply with the C standard? => bit shift can't exceed the limit (sizeof(int) -1). 
// bit shift 최대 7가능
int int_size_is_32() {
    unsigned x = 0;
    x -= 1;
    x ^= x>>1;
    return x == 0x80000000;
}

int int_size_is_16() {
    unsigned x = 0;
    x -= 1;
    x ^= x>>1;
    return x == 0x8000;
}


int main (){
    printf("%d",int_size_is_16());
}