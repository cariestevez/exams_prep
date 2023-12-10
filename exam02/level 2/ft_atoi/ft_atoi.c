// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	sign = 1;
	int num = 0;

	while ( str[i] != '\0' && ((str[i] >= 8 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

// int	main()
// {
// 	char *str = " +1a23";

// 	printf("my_atoi: %d\n", ft_atoi(str));
// 	printf("original atoi: %d\n", atoi(str));
// 	return (0);
// }