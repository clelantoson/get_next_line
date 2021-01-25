#include "get_next_line.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int bignum;

	bignum = n;
	if (n < 0)
	{
		bignum = -bignum;
		ft_putchar('-');
	}
	if (bignum >= 10)
		ft_putnbr(bignum / 10);
	ft_putchar(bignum % 10 + '0');
}
