#include <unistd.h>
#include <stdio.h>

int my_atoi(char *str)
{
	int i = 0;
	int num = 0;
	
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num);
}

int is_prime(int num)
{
	int i = 2;

	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void my_putnbr(int num)
{
	char	c = 0;

	if (num >= 10)
		my_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int	sum = 0;
	int	num = 0;

	if (argc == 2)
	{
		num = my_atoi(argv[1]);
		while (num > 1)
		{
			if (is_prime(num))
				sum = sum + num;
			num--;
		}
		my_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}