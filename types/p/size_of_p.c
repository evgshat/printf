#include "../../ft_printf.h"

int	size_of_p(int res)
{
	int		size;
	int		res_copy;
	char	*s_res;

	size = 0;
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 16;
		size++;
	}
	if (res == 0)
		size++;
	size = size + 2;
	s_res = ft_itoa(res);
	return (size);
}
