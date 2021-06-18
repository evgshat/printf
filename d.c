
// если ширина < кол-во цифр - выводим все цифры
// если ширина > кол-ва цифр - выводим цифры и пробелы слева
// если точность <  кол-во цифр - выводим все цифры
// если точность > кол-ва цифр - выводим цифры и нули слева

#include "ft_printf.h"

void	d(struct s_flags flags, va_list args)
{
	int		res;
	int		res_copy;
	int		size;
	char	*s_res;

	size = 0;
	// если нет ни ширины, ни точности
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		res = va_arg(args, int);
		printf("result = %d\n", res);
		res_copy = res;
		while (res_copy != 0)
		{
			res_copy = res_copy / 10;
			size++;
		}
		s_res = ft_itoa(res);
		write (1, s_res, size);
	}
}