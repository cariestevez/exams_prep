#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char *str = argv[1];

	if (argc == 2)
	{
		while (str[i] != '\0')
			i++;
		i--;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i--;
		while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || i == 0))
			i--;
		i++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}