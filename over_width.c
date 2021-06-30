#include "ft_printf.h"

int	over_width(int a, int b)
{
	int		dif_arg;
	int		i_dif_arg;

	dif_arg = a - b;
	i_dif_arg = 0;
	while (i_dif_arg < dif_arg)
	{
		write (1, " ", 1);
		i_dif_arg++;
	}
	return (i_dif_arg);
}