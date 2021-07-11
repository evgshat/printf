#include "../ft_printf.h"

int	processor(t_flags flags, va_list args)
{
	int	res;

	res = 0;
	if (flags.type == 'd' || flags.type == 'i')
		res += d(flags, args);
	if (flags.type == 'c')
		res += c(flags, args);
	if (flags.type == 's')
		res += s(flags, args);
	if (flags.type == 'x')
		res += x(flags, args);
	if (flags.type == 'X')
		res += big_x(flags, args);
	if (flags.type == 'p')
		res += p(flags, args);
	if (flags.type == 'u')
		res += u(flags, args);
	if (flags.type == '%')
		res += perc(flags);
	return (res);
}
// {
// 	struct s_flags	flags;
// 	int				res_end;

// 	res_end = 0;
// 	flags = new_parser_flags(format, args, i);
// 	*res = processor_type(flags, args);
// 	res_end += parser_end((char *)format, args, i);
// 	*res += res_end;
// 	return (*res);
// }
