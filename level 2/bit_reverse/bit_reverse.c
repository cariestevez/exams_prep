#include <stdio.h>

unsigned char reverse_octet (unsigned char octet)
{
	int	byte_len = 8;
	int	j_bit = 0;
	unsigned char	rev = 0;
	unsigned char	rev_copy = 0;

	while (byte_len-- > 0)
	{
		rev = (octet >> j_bit) & 1;
		rev = rev << byte_len;
		rev_copy = (rev_copy | rev ) + '0';
		j_bit++;
	}
	return (rev_copy);
}

int	main ()
{
	unsigned char	octet = 128;
	printf("%d\n", reverse_octet(octet));
}

/*
octet >>= 1; is equivalent to octet /= 2;

1 bit	(2^1)	=	2 valores
2 bits	(2^2)	=	4 valores
3 bits	(2^3)	=	8 valores
4 bits	(2^4)	=	16 valores
8 bits	(2^8)	=	256 valores ( =1 byte)
16 bits	(2^16)	=	65.536 valores
24 bits	(2^24)	=	16.777.216 valores

Posición 1: 2^0 = 1
Posición 2: 2^1 = 2
Posición 3: 2^2 = 4
Posición 4: 2^3 = 8
Y así sucesivamente.

Position value:		2^7		2^6		2^5		2^4		2^3		2^2		2^1		2^0
Digit value:		128		64		32		16		8		4		2		1
Binary Number:		1		1		1		1		1		1		1		1

(1x128) + (1x64) + (1x32) + (1x16) + (1x8) + (1x4) + (1x2) + (1x1) = 255.)
*/

/*
unsigned char reverse_bits(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}
*/