#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0;
	char *str = argv[1];
	char *replace = argv[2];
	char *c = argv[3];

	if (argc == 4 && replace[1] == '\0' && c[1] == '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] == replace[0])
				str[i] = c[0];
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}