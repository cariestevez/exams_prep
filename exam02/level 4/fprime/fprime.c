#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	num = 0;
	int	i = 2;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (atoi(argv[1]) <= 0)
		{
			printf("\n");
			return (0);
		}
		while (num != 1)
		{
			//printf("num = %d\n", num);
			if (num % i == 0)
			{
				printf("%d", i);
				num = num / i;
				if (num != 1)
					printf("*");
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}