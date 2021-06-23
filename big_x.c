#include "ft_printf.h"

void	big_x(struct s_flags flags, va_list args)
{
	int	chislo;

	chislo = va_arg(args, int);
	from_d_to_big_x(chislo);
	// удалить
	if (flags.flag_minus == 209)
	{
		chislo = 1;
	}
}