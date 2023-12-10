#include <stdio.h>

int	max(int *tab, unsigned int	len)
{
	int	max = 0;
	unsigned int	i = 0;

	if (tab == 0)
		return (0);
	max = tab[i];
	while ((i + 1) < len)
	{
		if (max < tab[i + 1])
			max = tab[i + 1];
		i++;
	}
	return (max);
}

// int	main ()
// {
// 	int	tab[7] = {-42, 0, -5, -64, -2, -68, -1};

// 	printf("%d\n", max(tab, 5));
// 	return (0);
// }