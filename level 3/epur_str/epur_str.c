#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			//if (i == 0 && (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n'))
			while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n'))
			{
				//printf("salta espacios\n");
				i++;
			}
			if (argv[1][i] != '\0' && !(argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n'))
			{
				//printf("no es espacio\n");
				if ((argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t' || argv[1][i - 1] == '\n') && (i - 1 != 0))
				{
				//	printf("pero antes había espacio->imprímelo\n");
					write(1, " ", 1);
				}
				while (argv[1][i] != '\0' && !(argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n'))
				{
				//	printf("imprime las letras\n");
					write(1, &argv[1][i], 1);
					i++;
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}