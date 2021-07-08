#include "../../ft_printf.h"

char	*res_for_u(va_list args, int *size)
{
	long long		res;
	char			*s_res;

	res = va_arg(args, unsigned int);
	*size = size_d(res);
	s_res = ft_itoa_unint(res);
	return (s_res);
}
