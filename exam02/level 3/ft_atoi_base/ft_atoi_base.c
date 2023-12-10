#include <stdio.h>

// int	valid_input(const char *str, int str_base)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	int	valid = 0;

// 	//ex; str = "1310" str_base = 2

// 	char maxbase_lower[17] = "0123456789abcdef";
// 	char maxbase_upper[17] = "0123456789ABCDEF";
// 	while (str[i] != '\0')
// 	{
// 		j = 0;
//		valid = 0;
// 		while (j <= str_base - 1)
// 		{
// 			if (str[i] == maxbase_lower[j] || str[i] == maxbase_upper[j])
// 				valid = 1;
// 			j++;
// 		}
// 		if (valid == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// another way of validating the input directly from the convertion loop, passing each caracter of the str 1 by 1
// int		isvalid(char c, int base)
// {
// 	char digits[17] = "0123456789abcdef";
// 	char digits2[17] = "0123456789ABCDEF";

// 	while (base--)
// 		if (digits[base] == c || digits2[base] == c)
// 			return (1);
// 	return (0);
// }

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	if (str_base == 0)
		return (0);
	//added after to check if the chars of the input str correspond to the given input base:
	//if (valid_input == 0)
	//	return (0);
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// single char input validation should go here:
	//while (isvalid(str[i], str_base) && str[i] != '\0')
		//	result = result * str_base + value_of(str[i]);
		//	i++;
	//this char checking is too generic but works if the given str is in accordance to the given str_base
	while (((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F')) && str[i] != '\0')
	{
		num = num * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			num = num + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			num += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			num += str[i] - 'A' + 10;
		i++;
	}
	if (i == 0)
		return (0);
	return (num * sign);
}

// int main()
// {
// 	char *str = "3ab2c";
// 	int	str_base = 5;

// 	printf("%d\n", ft_atoi_base(str, str_base));
// 	return (0);
// }