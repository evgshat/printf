// %[флаги][ширина][.точность][размер]тип
// cspdiuxX%

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list				args;
	int					proc_res;
	int					er;

	proc_res = 0;
	va_start(args, format);
	er = errors(format);
	proc_res = processor(format, args);
	return (proc_res);
}