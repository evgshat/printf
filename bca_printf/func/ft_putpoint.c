#include "../ft_printf.h"

static char	little_hex(unsigned int n)
{
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (n + '0');
}

void	ft_putpoint(unsigned long n)
{
	char	c;

	if (n > 15)
		ft_putpoint(n / 16);
	c = little_hex(n % 16);
	write(1, &c, 1);
}
