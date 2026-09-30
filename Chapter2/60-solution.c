#include <stdio.h>

unsigned replace_byte (unsigned x, int i, unsigned char b) {
	unsigned char* replaced_x = (unsigned char *) &x;
	replaced_x[i] = b;
	unsigned* y = (unsigned*) replaced_x;
	return *y;
}

int main()
{
	int x = 0x12345678;
	printf("%.2x",replace_byte(x, 0, 0xAB));

	return 0;
}
