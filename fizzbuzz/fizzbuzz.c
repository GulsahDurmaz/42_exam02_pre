#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char arr[10] = "0123456789";

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &arr[nbr % 10], 1);
}

int	main(void)
{
	int i = 0;

	while (i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_putnbr(i);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
