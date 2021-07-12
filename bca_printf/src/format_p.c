#include "../ft_printf.h"

static int	order_counter_p(unsigned long x)
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

void	format_p(t_values *elem)
{
	unsigned long	x;
	int				order;
	int				big;

	x = va_arg(elem->args, unsigned long);
	order = order_counter_p(x);
	elem->len += order + 2;
	big = biggest(order, elem->precision);
	if (elem->width > big && elem->flag_minus == 0 && elem->flag_zero == 0)
		elem->len += flag_writer(elem->width - big - 2, 0);
	if (elem->width > big && elem->flag_zero == 1 && elem->precision > 0)
		elem->len += flag_writer(elem->width - big - 2, 0);
	write(1, "0x", 2);
	if (elem->precision > elem->width && elem->flag_zero)
		elem->len += flag_writer(elem->precision - order, 1);
	if (elem->width > big && elem->flag_zero == 1)
		elem->len += flag_writer(elem->width - big - 2, 1);
	if (elem->precision > order && elem->flag_zero == 0)
		elem->len += flag_writer(elem->precision - order, 1);
	ft_putpoint(x);
	if (elem->width > big && elem->flag_minus == 1)
		elem->len += flag_writer(elem->width - big - 2, 0);
	clear_values(elem);
}
