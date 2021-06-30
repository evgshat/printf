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

// int main()
// {
// 	// int	res;
// 	// int		a = -4;
// 	// char	*n = "abcdefghijklmnop";
// 	// char	*r = "%%";

// 	// res = ft_printf("Simple input test");
// 	// ft_printf(" --- Return : %d\n", res);
// 	ft_printf("%8.5d", 34);
// }