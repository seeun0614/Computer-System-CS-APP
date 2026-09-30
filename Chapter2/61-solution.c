//A
#include <stdio.h>

int main()
{
    int x = 0x10000000;
    _Bool b = x;
    printf("%d",b);
}
//B
#include <stdio.h>

int main()
{
    int x = 0x00000000;
    _Bool b = x;
    printf("%d",!b);
}
//C
#include <stdio.h>

int main()
{
    int x = 0xffffff00;
    int lsb = x << 8*3;
    _Bool b = lsb;
    printf("%d",b);
}
//D
