#include "ft_printf.h"

int	write_s(int a, int b, char *s_res)
{
	int		dif_arg;
	int		i_dif_arg;

	dif_arg = a - b;
	i_dif_arg = 0;
	while (i_dif_arg <= dif_arg)
	{
		write (1, s_res, 1);
		i_dif_arg++;
		s_res++;
	}
	return (i_dif_arg);
}