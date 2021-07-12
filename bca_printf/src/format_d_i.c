#include "../ft_printf.h"

static int	order_counter(int x)
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

void	format_d_i(t_values *elem)
{
	int	x;
	int	order;
	int	big;

	x = va_arg(elem->args, int);
	order = order_counter(x);
	elem->len += order;
	big = biggest(order, elem->precision);
	if (x < 0)
		big++;
	if (elem->width > big)
		elem->len += space_writer(elem->width - big);
	if (x < 0)
		elem->len += write(1, "-", 1);
	if (elem->precision > order)
		elem->len += zero_writer(elem->precision - order);
	ft_putnbr(x);
	clear_values(elem);
}
