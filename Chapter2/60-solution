#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

unsigned replace_byte (unsigned x, int i, unsigned char b) {
    byte_pointer replaced_x = (byte_pointer)malloc(sizeof(unsigned char) * sizeof(x));

    replaced_x = (byte_pointer) &x;
    replaced_x[i] = b;
    printf("%.2x",replaced_x[2]);
    x = *replaced_x;
    free (replaced_x);
    
    return x;
}

int main()
{   
    unsigned int x = 0x12345678;
    replace_byte(x, 2, 0xAB);
    // printf("%.2x",replace_byte(x, 2, 0xAB));
    
    return 0;
}
