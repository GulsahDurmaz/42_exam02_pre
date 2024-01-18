//#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int	max;
	int	i = 0;

	max = tab[0];
	while (tab && len > 0)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
		len--;
	}
	return (max);
}
/*
int	main(void)
{
	int				arr[] = {-42, 0, -5, -64, -2, -68,-1};
	unsigned int	len = 7;

	printf("max nbr: %d", max(arr, len));
	return (0);
}
*/
