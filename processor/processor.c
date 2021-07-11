#include "../ft_printf.h"

int	processor(const char *format, va_list args, int *i)
{
	struct s_flags	flags;
	int				res;

	res = 0;
	flags = new_parser_flags(format, args, i);
	res = processor_type(flags, args);
	res += parser_end((char *)format, args, i);
	return (res);
}
