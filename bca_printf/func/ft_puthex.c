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

static char	big_hex(unsigned int n)
{
	if (n == 10)
		return ('A');
	if (n == 11)
		return ('B');
	if (n == 12)
		return ('C');
	if (n == 13)
		return ('D');
	if (n == 14)
		return ('E');
	if (n == 15)
		return ('F');
	return (n + '0');
}

void	ft_puthex(unsigned int n, char t)
{
	char	c;

	if (n > 15)
		ft_puthex(n / 16, t);
	if (t == 'x')
		c = little_hex(n % 16);
	else
		c = big_hex(n % 16);
	write(1, &c, 1);
}
