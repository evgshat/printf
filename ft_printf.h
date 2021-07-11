#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_flags
{
	char	type;
	int		fl_w;
	int		val_w;
	int		fl_m;
	int		fl_z;
	int		fl_p;
	int		val_p;
} t_flags;

void			parser_dot(t_flags *flags, char *format, int *i, va_list args);
t_flags			new_parser_flags(const char *format, va_list args, int *i);
void			parser_width(t_flags *flags, char *format, int *i, va_list args);
int				processor(const char *format, va_list args, int *i);
int				d(t_flags flags, va_list args);
char			*ft_itoa(int n);
int				c(t_flags flags, va_list args);
int				s(t_flags flags, va_list args);
size_t			ft_strlen (const char *str);
int				over_width(int a, int b);
int				over_percision(int a, int b);
void			write_for_s(struct s_flags flags, char	*s_res);
int				x(t_flags flags, va_list args);
int				from_d_to_x(unsigned long long chislo);
char			dictionary_from_d_to_x(int ost);
int				from_d_to_big_x(unsigned long long chislo);
int				big_x(t_flags flags, va_list args);
char			dictionary_from_d_to_big_x(int ost);
int				size_of_x(int res);
int				p(struct s_flags flags, va_list args);
int				from_d_to_p(unsigned long long chislo);
int				u(struct s_flags flags, va_list args);
char			*ft_itoa_unint(unsigned int n);
int				over_width_zero(int a, int b);
int				sum(int size);
size_t			ft_strlen (const char *str);
int				processor_type(struct s_flags flags, va_list args);
int				ft_atoi(const char *string);
int				ft_printf(char const *format, ...);
int				write_s(int p, char *s_res);
int				write_s_null(char *s_res, int size, int value_precision, int flag_presicion);
int				is_type(char ch);
int				ft_isdigit(int ch);
void			parser_minus(t_flags *flags, int *i);
void			parser_zero(t_flags *flags, int *i);
void			init_flag(t_flags *flags);
int				parser_end(char *format, va_list args, int *i);
int				write_d_s_res(char *s_res, int size);
int				d_w_and_p(t_flags flags, int size, char *s_res);
int				d_posit(t_flags flags, int size, char *s_res);
int				d_negat(t_flags flags, int size, char *s_res);
char			*res_for_d(va_list args, int *size);
long long int	size_d(long long int res);
int				write_d_ch(char ch);
int				d_only_w(t_flags flags, char *s_res, int size);
int				x_wp(t_flags flags, int size, int chislo);
int				big_x_wp(t_flags flags, int size, int chislo);
char			*res_for_u(va_list args, int *size);
int				u_only_w(t_flags flags, char *s_res, int size);
int				u_w_and_p(t_flags flags, int size, char *s_res);
int			write_before_perc(const char *format, int *i);
int				p_wp(t_flags flags, int size, int chislo);
char			*res_for_s(va_list args, int *size);
int				s_w_and_p(t_flags flags, char *s_res, int size);
int				s_less_wp(t_flags flags, char *s_res, int size);
int				s_over_w(t_flags flags, char *s_res, int size);
int				s_over_wp(t_flags flags, char *s_res, int size);
int				perc(t_flags flags);
int				size_of_p(unsigned long long res);
char			*itoa_for_p(unsigned long long n);

#endif