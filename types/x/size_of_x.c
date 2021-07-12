#include "../../ft_printf.h"

int	size_of_x(unsigned int res)
{
	int					size;
	unsigned int		res_copy;

	size = 0;
	if (res < 0)
		res_copy = res * (-1);
	else
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
