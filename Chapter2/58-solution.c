#include <stdio.h>

typedef unsigned char *byte_pointer;
int is_little_endian () {
    int n = 1;
    byte_pointer tmp =(byte_pointer) &n;
    if (tmp[0] == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{   
    printf("%d",is_little_endian());
  
    return 0;
}
