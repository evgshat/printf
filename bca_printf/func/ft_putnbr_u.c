#include "../ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	char	c;

	c = '_';
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
