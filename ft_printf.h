#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h> // для va_start

int				parser_dot(const char *point_dot, va_list args);
struct s_flags	parser_flags(const char *format, va_list args);
int				parser_width(va_list args);
void			processor(const char *format, struct s_flags flags, va_list args);
int				errors(const char *format);
void			d(struct s_flags flags, va_list args);
char			*ft_itoa(int n);

struct s_flags
{
	char	type;
	int		flag_width;
	int		value_width;
	int		flag_minus;
	int		flag_zero;
	int		flag_precision;
	int		value_precision;
	int		flag_star;
};

// struct s_flags	flagss = {0, 0, 0, 0, 0, 0};

#endif