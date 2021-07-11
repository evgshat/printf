#include "../../ft_printf.h"

int	size_of_x(int res)
{
	int		size;
	int		res_copy;

	size = 0;
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 16;
		size++;
	}
	if (res == 0)
		size++;
	return (size);
}