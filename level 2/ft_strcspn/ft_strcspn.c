#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == reject[0])
			break;
		i++;
	}
	return (i);
}

// int main ()
// {
// 	char *s = "wlat the hell?";
// 	char *reject = "w";

// 	printf("%s\n%s\n%lu\n", s, reject, strcspn(s, reject));
// 	printf("%s\n%s\n%lu\n", s, reject, ft_strcspn(s, reject));
// 	return (0);
// }