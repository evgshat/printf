#include "../ft_printf.h"

void	format_percent(t_values *elem)
{
	if (elem->flag_minus == 0)
		elem->len += flag_writer(elem->width - 1, elem->flag_zero);
	write(1, "%", 1);
	if (elem->flag_minus == 1)
		elem->len += flag_writer(elem->width - 1, elem->flag_zero);
	elem->len++;
	clear_values(elem);
}
