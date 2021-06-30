#include "ft_printf.h"

int	processor_type(struct s_flags flags, va_list args)
{
	int	res_d;
	int	res_c;
	int	res_s;
	int	res_x;
	int	res_big_x;
	int	res_p;
	int	res_u;

	res_d = 0;
	res_c = 0;
	res_s = 0;
	res_x = 0;
	res_big_x = 0;
	res_p = 0;
	res_u = 0;
	if (flags.type == 'd' || flags.type == 'i')
		res_d = d(flags, args);
	if (flags.type == 'c')
		res_c = c(flags, args);
	if (flags.type == 's')
		res_s = s(flags, args);
	if (flags.type == 'x')
		res_x = x(flags, args);
	if (flags.type == 'X')
		res_big_x = big_x(flags, args);
	if (flags.type == 'p')
		res_p = p(flags, args);
	if (flags.type == 'u')
		res_u = u(flags, args);
	return (res_d + res_c + res_s + res_x + res_big_x + res_p + res_u);
}