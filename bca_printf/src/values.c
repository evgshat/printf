#include "../ft_printf.h"

void	init_values(t_values *elem)
{
	elem->len = 0;
	elem->flag_plus = 0;
	elem->flag_minus = 0;
	elem->flag_zero = 0;
	elem->flag_grid = 0;
	elem->flat_space = 0;
	elem->width = 0;
	elem->precision = -1;
	elem->type = '0';
}

void	clear_values(t_values *elem)
{
	elem->flag_plus = 0;
	elem->flag_minus = 0;
	elem->flag_zero = 0;
	elem->flag_grid = 0;
	elem->flat_space = 0;
	elem->width = 0;
	elem->precision = -1;
	elem->type = '0';
}
