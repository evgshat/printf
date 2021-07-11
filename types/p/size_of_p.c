#include "../../ft_printf.h"

int	size_of_p(unsigned long long res)
{
	int						size;
	unsigned long long 		res_copy;

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
	return (size);
}
