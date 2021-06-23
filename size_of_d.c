#include "ft_printf.h"

int	size_of_d(int res)
{
	int		size;
	int		res_copy;
	char	*s_res;

	size = 0;
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	s_res = ft_itoa(res);
	return (size);
}