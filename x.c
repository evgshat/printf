#include "ft_printf.h"

void	x(struct s_flags flags, va_list args)
{
	int	chislo;

	chislo = va_arg(args, int);
	from_d_to_x(chislo);
}