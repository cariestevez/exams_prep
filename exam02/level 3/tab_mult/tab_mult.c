#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned int	num = 0;
	int	i = 0;
	int	mult = 1;

	if (argc > 1)
	{
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			num = (num * 10) + (argv[1][i] - '0');
			i++;
		}
		while (mult <= 9)
		{
			printf("%d x %d = %d\n", mult, num, mult*num);
			mult++;
		}
	}
	else
		printf("\n");
	return (0);
}