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
void			processor(const char *format, struct s_flags flags,
					va_list args);
int				errors(const char *format);
void			d(struct s_flags flags, va_list args);
char			*ft_itoa(int n);
void			c(struct s_flags flags, va_list args);
void			s(struct s_flags flags, va_list args);
size_t			ft_strlen (const char *str);
void			over_width(struct s_flags flags, int size, int a, int b);
void			over_percision(struct s_flags flags, int size, int a, int b);
int				size_of_d(int res);
void			write_for_s(struct s_flags flags, char	*s_res);
void			x(struct s_flags flags, va_list args);
void			from_d_to_x(int chislo);
char			dictionary_from_d_to_x(int ost);
void			from_d_to_big_x(int chislo);
void			big_x(struct s_flags flags, va_list args);
char			dictionary_from_d_to_big_x(int ost);
int				size_of_x(int res);

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