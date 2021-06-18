#include "ft_printf.h"

int	parser_dot(const char *point_dot, va_list args)
{
	int	ind_arg;
	int	res;

	if (*point_dot >= '1' && *point_dot <= '9')
	{
		res = *point_dot - '0';
		return (res);
	}
	if (*point_dot == '*')
	{
		res = va_arg(args, int);
		va_end(args);
		return (res);
	}
	else
		return (0);
}