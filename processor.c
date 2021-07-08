// если перед % есть текст - то выводим

#include "ft_printf.h"

int	processor(const char *format, va_list args, int *i)
{
	int				res;
	struct s_flags	flags;

	res = 0;
	// write_before_perc((char *)format, &i);
	flags = new_parser_flags(format, args, i);
	res = res + processor_type(flags, args);
	res = res + parser_end((char *)format, args, i);
	return (res);
}






// printf("type = %c\nflag_width = %d\nvalue_width = %d\nflag_minus = %d\nflag_zero = %d\nflag_precision = %d\nvalue_precision = %d\nflag_star = %d\n",
		// flags.type, flags.flag_width,
		// flags.value_width, flags.flag_minus, flags.flag_zero,
		// flags.flag_precision, flags.value_precision, flags.flag_star);