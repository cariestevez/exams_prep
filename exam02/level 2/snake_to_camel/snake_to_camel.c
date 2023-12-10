#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int letters = 0;
	char *str = NULL;

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] != '_' && argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\n')
				letters++;
			i++;
		}
		//printf("letters: %d\n", letters);
		str = (char *)malloc(sizeof(char) * (letters + 1));
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (i == 0 && (argv[1][i] <= 'A' && argv[1][i] <= 'Z'))
			{
				// printf("argv[1][%d]=%c\n", i, argv[1][i]);
				// printf("haz minúscula\n");
				str[j] = argv[1][i] + 32;
				j++;
				i++;
			}
			else if (argv[1][i] == '_' || argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n')
			{
				// printf("argv[1][%d]=%c\n", i, argv[1][i]);
				// printf("solo salta\n");
				i++;
			}
			else if (argv[1][i - 1] == '_' && (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
			{
				// printf("ATENCION: argv[1][%d - 1]=%c\n", i, argv[1][i - 1]);
				// printf("argv[1][%d]=%c\n", i, argv[1][i]);
				// printf("haz mayúscula\n");
				str[j] = argv[1][i] - 32;
				j++;
				i++;
			}
			else
			{
				// printf("argv[1][%d]=%c\n", i, argv[1][i]);
				// printf("solo copia\n");
				str[j] = argv[1][i];
				j++;
				i++;
			}
			//printf("str[%d]=%c\n", j, str[j]);
		}
		str[j] = '\0';
		write(1, str, j);
		//write(1, "\n", 1);
		//printf("%s\n", str);
	}
	write(1, "\n", 1);
	free(str);
	return (0);
}