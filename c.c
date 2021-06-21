// добавить флаги минус и ноль
// проверить, что норм работает, когда ширина = 1

#include "ft_printf.h"

void	c(struct s_flags flags, va_list args)
{
	char	res;
	int		i;

	res = va_arg(args, int);
	if (flags.flag_width != 0)
	{
		i = 0;
		while (i < flags.value_width)
		{
			write(1, &res, 1);
			i++;
		}
		write (1, &res, 1);
	}
	if (flags.flag_width == 0)
		write(1, &res, 1);
}