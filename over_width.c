#include "ft_printf.h"

void	over_width(struct s_flags flags, int a, int b)
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
}