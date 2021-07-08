#include "../ft_printf.h"

char	dictionary_from_d_to_big_x(int ost)
{
	char	c_ost;

	if (ost == 0)
		c_ost = '0';
	if (ost >= 1 && ost <= 9)
		c_ost = ost + '0';
	if (ost == 10)
		c_ost = 'A';
	if (ost == 11)
		c_ost = 'B';
	if (ost == 12)
		c_ost = 'C';
	if (ost == 13)
		c_ost = 'D';
	if (ost == 14)
		c_ost = 'E';
	if (ost == 15)
		c_ost = 'F';
	return (c_ost);
}
