#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int copy_nbr = nbr;
	int	len = 0;
	char *num = NULL;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	if (nbr == 0)
		return ("0\0");
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	nbr = copy_nbr;
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (nbr < 0)
	{
		num[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr)
	{
		num[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (num);
}

// int main()
// {
// 	int	nbr = -1917;

// 	printf("%s\n", ft_itoa(nbr));
// }