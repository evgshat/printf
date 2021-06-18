#include "ft_printf.h"

int	parser_width(va_list args)
{
	int	res;

	res = va_arg(args, int);
	// va_end(args);
	return (res);
}