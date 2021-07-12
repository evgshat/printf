#include "../ft_printf.h"

static int	order_counter_u(unsigned int x)
{
	int	i;

	i = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

void	format_u(t_values *elem)
{
	unsigned int	x;
	int				order;
	int				big;

	x = va_arg(elem->args, unsigned int);
	order = order_counter_u(x);
	elem->len += order;
	big = biggest(order, elem->precision);
	if (elem->width > big)
		elem->len += space_writer(elem->width - big);
	if (elem->precision > order)
		elem->len += zero_writer(elem->precision - order);
	ft_putnbr_u(x);
	clear_values(elem);
}
