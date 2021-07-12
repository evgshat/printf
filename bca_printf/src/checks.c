#include "../ft_printf.h"

void	check_type(t_values *elem)
{
	if (elem->type == 'c')
		format_c(elem);
	if (elem->type == 's')
		format_s(elem);
	if (elem->type == 'd' || elem->type == 'i')
		format_d_i(elem);
	if (elem->type == 'u')
		format_u(elem);
	if (elem->type == 'x' || elem->type == 'X')
		format_x(elem);
	if (elem->type == 'p')
		format_p(elem);
	if (elem->type == '%')
		format_percent(elem);
}

void	flag_ignor(t_values *elem)
{
	if (elem->flag_plus == 1)
		elem->flat_space = 0;
	if (elem->flag_minus == 1)
		elem->flag_zero = 0;
}

int	biggest(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
