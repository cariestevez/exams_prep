#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main (int argc, char **argv)
{
	int	a = 0;
	int b = 0;

	if (argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		if (argv[2][0] == '+')
			printf("%d", a + b);
		else if (argv[2][0] == '-')
			printf("%d", a - b);
		else if (argv[2][0] == '*')
			printf("%d", a * b);
		else if (argv[2][0] == '/')
			printf("%d", a / b);
		else if (argv[2][0] == '%')
			printf("%d", a % b);
	}
	printf("\n");
	return (0);
}