#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char alpha[26] = "abcdefghijklmnopqrstuvwxyz";

	if (argc == 2)
	{
		while(argv[1][i] != '\0')
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
			{
				j = 0;
				while (alpha[j] != '\0')
				{
					if (alpha[j] == argv[1][i])
					{
						argv[1][i] = alpha[25 - j];
						break;
					}
					else if (alpha[j] - 32 == argv[1][i])
					{
						argv[1][i] = alpha[25 - j] - 32;
						break;
					}
					j++;
				}
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
