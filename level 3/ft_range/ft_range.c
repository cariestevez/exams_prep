#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	count = 1;
	int	copy = start;
	int	i = 0;
	int	*arr = 0;

	while (copy < end || copy > end)
	{
		count++;
		if (copy < end)
			copy++;
		else
			copy--;
	}
	arr = (int *)malloc(sizeof(int) * count);
	while(i < count)
	{
		arr[i] = start;
		i++;
		if (start < end)
			start++;
		else
			start--;
	}
	return (arr);
}

// int main()
// {
// 	int	i = 0;
// 	int *nums = ft_range(-1, 2);
// 	while (nums[i] != 2)
// 	{
// 		printf("nums[%d] = %d\n", i, nums[i]);
// 		i++;
// 	}
// 	printf("nums[%d] = %d\n", i, nums[i]);
// 	i++;
// 	printf("i:%d\n", i);
// 	return (0);
// }
// -1<2		0<2		1<2		2<2
// 2		3		4
// 0		1		2

// 0>-3		-1>-3	-2>-3
// 2		3		4
// -1		-2		-3