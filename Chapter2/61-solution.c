//A
#include <stdio.h>

int main()
{
    int x = 0x10000000;
    printf("%d",!!x);
}
//B
#include <stdio.h>

int main()
{
    int x = 0xffefffff;
    printf("%d",!!~x);
}
//C
#include <stdio.h>

int main()
{
    int x = 0xffffff00;
    int lsb = x & 0x000000ff;
    printf("%d",!!lsb);
}
//D
#include <stdio.h>

int main()
{
    int x = 0xefffffff;
    int msb = x & 0xff000000;
    msb = ~msb & 0xff000000;
    printf("%d",!!msb);
}
