#include <unistd.h>
#include <stdlib.h>

void	ft_puchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 4 || argv[2][1] != 0 || argv[2][1] != 0)
	{
		write(1, "\n", 1);
		exit (1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == *argv[2])
			argv[1][i] = *argv[3];
		i++;
	}
	i = 0;
	while (argv[1][i])
	{
		ft_puchar(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	exit (0);
}
