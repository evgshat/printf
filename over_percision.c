#include "ft_printf.h"

void	over_percision(struct s_flags flags, int size, int a, int b)
{
	int		dif_arg;
	int		i_dif_arg;

	dif_arg = a - b;
	i_dif_arg = 0;
	while (i_dif_arg < dif_arg)
	{
		write (1, "0", 1);
		i_dif_arg++;
	}
	// удалить
	if (flags.flag_minus == 209)
	{
		dif_arg = 1;
		size = 1;
	}
}