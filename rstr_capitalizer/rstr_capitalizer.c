#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (j == 0 || (argv[i][j + 1] == '\0')))
				argv[i][j] -= 32;
			else if (j == 0 && (argv[i][j] >= 'A' && argv[i][j] <= 'Z'))
				argv[i][j] += 32;
			else if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')
				&& ((argv[i][j - 1] >= 'a' && argv[i][j - 1] <= 'z') || (argv[i][j - 1] >= 'A' && argv[i][j - 1] <= 'Z'))
				&& ((argv[i][j + 1] == 32) || (argv[i][j + 1] >= 8 && argv[i][j + 1] <= 13)))
				argv[i][j] -= 32;
			else if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')
				&& ((argv[i][j + 1] == 32) || (argv[i][j + 1] >= 8 && argv[i][j + 1] <= 13))
				&& ((argv[i][j - 1] == 32) || (argv[i][j - 1] >= 8 && argv[i][j - 1] <= 13)))
				argv[i][j] -= 32;
			else if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z')
				&& (((argv[i][j - 1] == 32) || (argv[i][j - 1] >= 8 && argv[i][j - 1] <= 13)) || ((argv[i][j - 1] >= 'A' && argv[i][j - 1] <= 'Z') || (argv[i][j - 1] >= 'a' && argv[i][j - 1] <= 'z')))
				&& ((argv[i][j + 1] >= 'A' && argv[i][j + 1] <= 'Z') || (argv[i][j + 1] >= 'a' && argv[i][j + 1] <= 'z')))
				argv[i][j] += 32;
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	if (argc == 1)
		write(1, "\n", 1);
	return (0);
}