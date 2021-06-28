#include "ft_printf.h"

void	from_d_to_p(int chislo)
{
	write (1, "0", 1);
	write (1, "x", 1);
	from_d_to_x(chislo);
}