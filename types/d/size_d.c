#include "../../ft_printf.h"

long long int	size_d(long long int res)
{
	long long	res_copy;
	int			size;

	size = 0;
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	if (res == 0)
		size++;
	if (res < 0)
		size++;
	return (size);
}
