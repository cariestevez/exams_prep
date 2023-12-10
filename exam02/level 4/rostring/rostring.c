#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int flag = 0;

	if (argc != 1)
	{
		while (argv[1][i] != '\0' && is_space(argv[1][i]))
			i++;
		start = i;
		while (argv[1][i] != '\0' && !(is_space(argv[1][i])))
			i++;
		end = i;
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] != '\0' && is_space(argv[1][i]))
				i++;
			while (argv[1][i] != '\0' && !(is_space(argv[1][i])))
			{
				write(1, &argv[1][i], 1);
				flag = 1;
				i++;
				if (is_space(argv[1][i]))
					write(1, " ", 1);
			}
		}
		if (flag == 1)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
		write(1, "\n", 1);
		return (0);
	}
}
