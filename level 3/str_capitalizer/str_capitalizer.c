#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;

	if (argc > 1)
	{
		while (argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				if (j == 0 && (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
					argv[i][j] = argv[i][j] - 32;
				else if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t' || argv[i][j - 1] == '\n'))
					argv[i][j] = argv[i][j] - 32;
				else if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z') && j != 0 && !(argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t' || argv[i][j - 1] == '\n'))
					argv[i][j] = argv[i][j] + 32;
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}