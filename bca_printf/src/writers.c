#include "../ft_printf.h"

int	flag_writer(int n, int zero)
{
	int		i;
	char	c;

	i = 0;
	if (zero)
		c = '0';
	else
		c = ' ';
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	space_writer(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	zero_writer(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
