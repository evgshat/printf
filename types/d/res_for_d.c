#include "../../ft_printf.h"

char	*res_for_d(va_list args, int *size)
{
	int		res;
	char	*s_res;

	res = va_arg(args, int);
	*size = size_d(res);
	s_res = ft_itoa(res);
	return (s_res);
}
