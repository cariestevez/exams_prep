#include <stdlib.h>
#include <stdio.h>


int	*ft_rrange(int start, int end)
{
	int i = 0;
	int count = 0;
	int direction = 0;
	int *arr = NULL;

	if (end >= start)
	{
		count = end - start + 1;
		direction = -1;
	}
	else
	{
		count = start - end + 1;
		direction = 1;
	}
	// printf("size of arr: i = %d\n", count);
	// printf("direction: %d\n", direction);
	arr = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (i < count)
	{
		arr[i] = end;
	//	printf("arr[%d]=%d, ", i, arr[i]);
		if (direction == -1)
			end--;
		else
			end++;
		i++;
	}
	return(arr);

}

// int main()
// {
// 	int i = 0;
// 	int *arr = NULL;

// 	arr = ft_rrange(-1, 2);
// 	while (i < 4)
// 	{
// 		printf("IN MAIN: %d, ", arr[i]);
// 		i++;
// 	}
// }