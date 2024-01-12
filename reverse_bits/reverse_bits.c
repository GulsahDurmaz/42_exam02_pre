#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
		//printf("1: octet: %c res: %c\n", octet, res);
	}
	return (res);
}

unsigned char	reverse_bits2(unsigned char octet)
{
	unsigned char	result = 0;

	for	(int i = 0; i < 8; ++i)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		//printf("1: octet: %c result: %c\n", octet, result);
	}
	return result;
}

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int	i = 8;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}

int	main ()
{
	unsigned char	octet = 112;

	printf("unsigned char octet: %hhu\n", octet);
	print_bits(octet);
	printf("\n");
	print_bits(octet >> 4);
	printf("\n");
	print_bits(octet << 4);
	printf("\n");
	print_bits((octet >> 4) | (octet << 4));
	printf("\n");
    // printf("\n");
	// printf("reverse bits 1: %hhu\n", reverse_bits(octet));
	// print_bits(reverse_bits(octet));
    // printf("\n");
	// printf("reverse bits 2: %hhu\n", reverse_bits2(octet));
	// print_bits(reverse_bits2(octet));
    // printf("\n");
	return (0);
}
