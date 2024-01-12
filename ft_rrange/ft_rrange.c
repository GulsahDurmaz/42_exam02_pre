#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	size;

	size = abs(start - end);
	range = (int*)(malloc)(sizeof(int) * size);
	while (range && size >= 0)
	{
		if (end > start)
			range[size] = start++;
		else
			range[size] = start--;
		size--;
	}
	return (range);
}
/*
int	main(void)
{
	int	*range;
	int	i = 0;

	range = ft_rrange(0, -3);
	while (i < 4)
		printf("%d\n", range[i++]);
	return (0);
}
*/
