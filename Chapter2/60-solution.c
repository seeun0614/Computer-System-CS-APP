#include <stdio.h>

unsigned replace_byte (unsigned x, int i, unsigned char b) {
	unsigned masked_x = x & ~(0xff << i*8);
	unsigned unsigned_b = (unsigned) b ;
	unsigned_b = unsigned_b << i*8;
	return masked_x | unsigned_b;
	
}

int main()
{
	int x = 0x12345678;
	printf("%.2x",replace_byte(x, 0, 0xAB));

	return 0;
}
