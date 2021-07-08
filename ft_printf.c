// %[флаги][ширина][.точность][размер]тип
// cspdiuxX%

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list				args;
	int					proc_res;
	int 				i;
	// int					er;

	proc_res = 0;
	i = 0;
	va_start(args, format);
	// er = errors(format);
	write_before_perc((char *)format, &i);
	proc_res = processor(format, args, &i);
	return (proc_res);
}