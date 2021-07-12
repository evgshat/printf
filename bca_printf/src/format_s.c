#include "../ft_printf.h"

static void	left_align(t_values *elem, char *str, size_t l)
{
	elem->len += write(1, str, l);
	if ((size_t)elem->width > l)
		elem->len += space_writer(elem->width - (int)l);
}

static void	right_align(t_values *elem, char *str, size_t l)
{
	if (elem->flag_zero)
	{
		if ((size_t)elem->width > l)
			elem->len += zero_writer(elem->width - (int)l);
	}
	else
	{
		if ((size_t)elem->width > l)
			elem->len += space_writer(elem->width - (int)l);
	}
	elem->len += write(1, str, l);
}

void	format_s(t_values *elem)
{
	char	*str;
	size_t	l;

	str = va_arg(elem->args, char *);
	if (!str)
		str = "(null)";
	l = str_null_len(str);
	if (elem->precision != -1 && (size_t)elem->precision < l)
		l = elem->precision;
	if (elem->flag_minus)
		left_align(elem, str, l);
	else
		right_align(elem, str, l);
	clear_values(elem);
}
