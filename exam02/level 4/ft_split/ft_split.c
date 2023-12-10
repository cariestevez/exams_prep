#include <stdio.h>
#include <stdlib.h>

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char **ft_split(char *str)
{
	int i = 0;
	int words = 0;
	int letters = 0;
	int counter = 0;
	char **matrix = NULL;

	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i] && !is_whitespace(str[i]))
		{
			words++;
			while (str[i] && !is_whitespace(str[i]))
				i++;
		}
	}
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	words = -1;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i] && !is_whitespace(str[i]))
		{
			words++;
			letters = 0;
			while (str[i] && !is_whitespace(str[i]))
			{
				letters++;
				i++;
			}
			matrix[words] = (char *)malloc(sizeof(char) * (letters + 1));
			counter = 0;
			while (counter < letters)
			{
				matrix[words][counter] = str[i - letters + counter];
				counter++;
			}
			matrix[words][counter] = '\0';
		}
	}
	matrix[words + 1] = NULL; // Null-terminate the matrix.
	return (matrix);
}

// int main(int argc, char **argv)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	char *string = argv[1];

// 	if (argc == 1)
// 		return (0);
// 	char **matrix = ft_split(string);
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		while (matrix[i][j])
// 		{
// 			printf("%c ", matrix[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	// Free memory.
// 	for (i = 0; matrix[i] != NULL; i++) {
// 		free(matrix[i]);
// 	}
// 	free(matrix);
// 	return (0);
// }