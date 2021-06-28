#include "ft_printf.h"
struct s_flags	pre_main(const char *format, ...)
{
	va_list				args;
	struct s_flags		res;
	int					proc_res;

	va_start(args, format);
	res = parser_flags(format, args);
	// printf("type = %c\nflag_width = %d\nvalue_width = %d\nflag_minus = %d\nflag_zero = %d\nflag_precision = %d\nvalue_precision = %d\nflag_star = %d\n",
	// 	res.type, res.flag_width,
	// 	res.value_width, res.flag_minus, res.flag_zero,
	// 	res.flag_precision, res.value_precision, res.flag_star);
	proc_res = processor(format, res, args);
	printf("\n%d", proc_res);
	return (res);
}

int	main(void)
{
	char	*format;
	int		res;

	format = (char *)malloc(sizeof(char) * 2);
	format = "%c";
	res = errors(format);
	pre_main(format, 'd');
	// printf("res = %d\n", res);
	if (res == 0)
		return (-1);
	else
		return (0);
}