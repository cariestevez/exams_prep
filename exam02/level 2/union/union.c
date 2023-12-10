#include <unistd.h>

void ft_compare(char *printed_char, char *str)
{
	int i = 0;
//full_ascii[100] == 0 --> full_ascii[100] = 1 
//--> hay una 'd' en la str, así que marcamos la posición de 'd' en ascii (100) con una flag (en este caso 1)
//--> en la siguiente vez que comparemos una str con nuestro array de ascii
//comprobamos si está marcada (ya impresa)
	while (str[i])
	{
		if (printed_char[(unsigned int)str[i]] == 0)
		{
			write(1, &str[i], 1);
			printed_char[(unsigned int)str[i]] = 1;
		}
		i++;
	}
	
}

int main(int argc, char **argv)
{
	char	full_ascii[256] = {0};

	if (argc == 3)
	{
		ft_compare(full_ascii, argv[1]);
		ft_compare(full_ascii, argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}