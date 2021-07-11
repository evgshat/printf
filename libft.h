/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:30:11 by lcharlet          #+#    #+#             */
/*   Updated: 2021/07/11 17:42:01 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int			ft_atoi(const char *string);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t number, size_t size);
int			ft_isalnum(int ch);
int			ft_isalpha(int ch);
int			ft_isascii(int ch);
int			ft_isdigit(int ch);
int			ft_isprint(int ch);
char		*ft_itoa(int n);
void		*ft_memccpy (void *destination, const void *source,
				int c, size_t n);
void		*ft_memchr(const void *buf, int c, size_t count);
int			ft_memcmp (const void *s1, const void *s2, size_t n);
void		*ft_memcpy (void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset (void *b, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr (const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat (char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy (char *dst, const char *src, size_t dstsize);
size_t		ft_strlen (const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int ch);
int			ft_toupper(int ch);

#endif
