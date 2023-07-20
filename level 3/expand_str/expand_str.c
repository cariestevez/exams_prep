#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 2)
	{
		if (argv[1][0] == 32 || (argv[1][0] >= 8 && argv[1][0] <= 13))
			i++;
		while(argv[1][i] != '\0')
		{
			if (argv[1][i] == 32 || (argv[1][i] >= 8 && argv[1][i] <= 13))
			{
				while ((argv[1][i] == 32 || (argv[1][i] >= 8 && argv[1][i] <= 13)) && argv[1][i] != '\0')
					i++;
				if (argv[1][i] != '\0')
					write (1, "   ", 3);
			}
			else
			{
				write (1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}