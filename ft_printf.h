#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

int				parser_dot(const char *point_dot, va_list args);
struct s_flags	parser_flags(const char **format, va_list args);
int				parser_width(va_list args);
int				processor(const char *format, va_list args);
int				errors(const char *format);
int				d(struct s_flags flags, va_list args);
char			*ft_itoa(int n);
int				c(struct s_flags flags, va_list args);
int				s(struct s_flags flags, va_list args);
size_t			ft_strlen (const char *str);
int				over_width(int a, int b);
int				over_percision(int a, int b);
int				size_of_d(int res);
void			write_for_s(struct s_flags flags, char	*s_res);
int				x(struct s_flags flags, va_list args);
int				from_d_to_x(unsigned long long chislo);
char			dictionary_from_d_to_x(int ost);
int				from_d_to_big_x(unsigned long long chislo);
int				big_x(struct s_flags flags, va_list args);
char			dictionary_from_d_to_big_x(int ost);
int				size_of_x(int res);
int				p(struct s_flags flags, va_list args);
int				from_d_to_p(int chislo);
int				u(struct s_flags flags, va_list args);
char			*ft_itoa_unint(unsigned int n);
int				over_width_zero(int a, int b);
int				sum(int size);
size_t			ft_strlen (const char *str);
int				processor_type(struct s_flags flags, va_list args);
int				ft_atoi(const char *string);
int				ft_printf(char const *format, ...);
int				write_s(int p, char *s_res);
int				write_s_null(char *s_res, int size);
struct s_flags	new_parser_flags(const char **format, va_list args);

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