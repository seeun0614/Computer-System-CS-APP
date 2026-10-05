#include <stdio.h>

unsigned f2u(float x);

int float_le (float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return sx && sy ? ((ux << 1) >= (uy << 1 ))
                    : ((ux << 1) <= (uy << 1 )) && (sx*!!(ux << 1) >= sy * !!(uy << 1));

}

int main () {

}