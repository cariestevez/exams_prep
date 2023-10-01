// #include <stdio.h>
// #include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	char *dup;

	while(src[i] != '\0')
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while(src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = src[i];
	return (dup);
}

// int	main()
// {
// 	char *src = "holi!";

// 	printf("src: %s\ndup: %s\n", src, ft_strdup(src));
// }