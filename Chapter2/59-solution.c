#include <stdio.h>

typedef unsigned char *byte_pointer;

int main()
{   
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;
    
    byte_pointer x_p = (byte_pointer) &x;
    byte_pointer y_p = (byte_pointer) &y;
    
    byte_pointer com_xy;
    
    for (int i =0; i<3; i++) {
        com_xy[i] = y_p[3-i];
    }
    
    com_xy[3] = x_p[0];
    
    for (int i =0; i<4; i++) {
        printf("%.2x",com_xy[i]);
    }
    
    
    return 0;
}
