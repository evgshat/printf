#include "libft.h"

static char	*int_char(int sign, int cnt, long n)
{
	int		ost;
	char	*str;

	ost = 0;
	str = malloc(cnt + 1);
	if (str == 0)
		return (NULL);
	str[cnt] = '\0';
	if (sign == 1)
		str[0] = '-';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (cnt >= 0)
	{
		ost = n % 10;
		str[cnt - 1] = ost + '0';
		n = n / 10;
		if (n == 0)
			break ;
		cnt--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		cnt;
	int		sign;
	long	cpy_n;
	char	*str;

	sign = 0;
	cnt = 0;
	cpy_n = n;
	if (n < 0)
	{
		cnt++;
		sign = 1;
		cpy_n = cpy_n * (-1);
	}
	else if (n == 0)
		cnt = 1;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	str = int_char(sign, cnt, cpy_n);
	return (str);
}
