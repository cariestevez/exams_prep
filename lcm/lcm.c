#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	num;
	
	num = 0;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		num = a;
	else
		num = b;
	while (1)
	{
		if (num % a == 0 && num % b == 0)
			return (num);
		num++;
	}
}
