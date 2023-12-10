#include <unistd.h>

int	rev_wstr(char *str, int i)
{
	int	end = 0;
	int	temp_position = 0;

	end = i;
	while (str[i] != 32 && !(str[i] >= 8 && str[i] <= 13) && i >= 0)
		i--;
	temp_position = i;
	if (i != 0)
		i += 1;
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (temp_position);
}

int main(int argc, char **argv)
{
	int i = 0;
	char *str = argv[1];

	if (argc == 2)
	{
		while (str[i] != '\0')
			i++;
		while (i != 0)
		{
			i = rev_wstr(str, i - 1);
			if (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
			{
				i--;
				write(1, " ", 1);
			}
			i++;
		}
		
	}
	write (1, "\n", 1);
	return (0);
}