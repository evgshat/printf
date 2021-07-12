#include "../ft_printf.h"

static int	left_align(int w, char c)
{
	int	x;

	x = 0;
	x += write(1, &c, 1);
	x += space_writer(w - 1);
	return (x);
}

static int	rigth_align(int w, char c, int zero)
{
	int	x;

	x = 0;
	if (zero)
		x += zero_writer(w - 1);
	else
		x += space_writer(w - 1);
	x += write(1, &c, 1);
	return (x);
}

void	format_c(t_values *elem)
{
	char	c;

	c = va_arg(elem->args, unsigned int);
	if (elem->flag_minus)
		elem->len += left_align(elem->width, c);
	else
		elem->len += rigth_align(elem->width, c, elem->flag_zero);
	clear_values(elem);
}
