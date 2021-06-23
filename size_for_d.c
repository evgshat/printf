// пока не используется

#include "ft_printf.h"

char	*size_of_d(va_list args)
{
	int		size;
	int		res;
	int		res_copy;
	char	*s_res;

	size = 0;
	res = va_arg(args, int);
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	s_res = ft_itoa(res);
	return (s_res);
}