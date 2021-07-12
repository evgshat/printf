#include "../ft_printf.h"

static int	order_counter_x(unsigned int x)
{
	int	i;

	i = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

void	format_x(t_values *elem)
{
	unsigned int	x;
	int				order;
	int				big;

	x = va_arg(elem->args, unsigned int);
	order = order_counter_x(x);
	elem->len += order;
	big = biggest(order, elem->precision);
	if (elem->width > big)
		elem->len += space_writer(elem->width - big);
	if (elem->precision > order)
		elem->len += zero_writer(elem->precision - order);
	ft_puthex(x, elem->type);
	clear_values(elem);
}
