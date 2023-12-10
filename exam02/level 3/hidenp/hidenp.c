#include <unistd.h>

int	is_hidden(char *s1, char *s2)
{
	int	i = 0;
	int j = 0;

	while (s1[i] != '\0')
	{
		if (!s2[j] && s1[i])
			return (0);
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				i++;
			j++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char *s1 = argv[1];
	char *s2 = argv[2];

	if (argc != 3)
	{	
		write(1, "\n", 1);
		return (0);
	}
	if (is_hidden(s1, s2))
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}