#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


void	test_pointer(void *x)
{
	printf("============================================\n");
	printf("=============== POINTER TEST ===============\n");
	printf("============================================\n");
	printf("  | %d\n", printf("orig        | %p", x));
	printf("  | %d\n", ft_printf("self        | %p", x));
	printf("  | %d\n", printf("orig        | % p", x));
	printf("  | %d\n", ft_printf("self        | % p", x));
	printf("  | %d\n", printf("orig      20| %20p", x));
	printf("  | %d\n", ft_printf("self      20| %20p", x));
	printf("  | %d\n", printf("orig   20.15| %20.15p", x));
	printf("  | %d\n", ft_printf("self   20.15| %20.15p", x));
	printf("  | %d\n", printf("orig   15.20| %15.20p", x));
	printf("  | %d\n", ft_printf("self   15.20| %15.20p", x));
	printf("  | %d\n", printf("orig     -20| %-20p", x));
	printf("  | %d\n", ft_printf("self     -20| %-20p", x));
	printf("  | %d\n", printf("orig    -.20| %-.20p", x));
	printf("  | %d\n", ft_printf("self    -.20| %-.20p", x));
	printf("  | %d\n", printf("orig  -20.15| %-20.15p", x));
	printf("  | %d\n", ft_printf("self  -20.15| %-20.15p", x));
	printf("  | %d\n", printf("orig  -15.20| %-15.20p", x));
	printf("  | %d\n", ft_printf("self  -15.20| %-15.20p", x));
	printf("  | %d\n", printf("orig     020| %020p", x));
	printf("  | %d\n", ft_printf("self     020| %020p", x));
	printf("  | %d\n", printf("orig    0.20| %0.20p", x));
	printf("  | %d\n", ft_printf("self    0.20| %0.20p", x));
	printf("  | %d\n", printf("orig  020.15| %020.15p", x));
	printf("  | %d\n", ft_printf("self  020.15| %020.15p", x));
	printf("  | %d\n", printf("orig  015.20| %015.20p", x));
	printf("  | %d\n", ft_printf("self  015.20| %015.20p", x));
	printf("  | %d\n", printf("orig    -020| %-020p", x));
	printf("  | %d\n", ft_printf("self    -020| %-020p", x));
	printf("  | %d\n", printf("orig -020.15| %-020.15p", x));
	printf("  | %d\n", ft_printf("self -020.15| %-020.15p", x));
	printf("  | %d\n", printf("orig -015.20| %-015.20p", x));
	printf("  | %d\n", ft_printf("self -015.20| %-015.20p", x));
}

void test_character(char x)
{
	printf("============================================\n");
	printf("============== CHARACTER TEST ==============\n");
	printf("============================================\n");
	printf("  | %d\n", printf("orig        | %c", x));
	printf("  | %d\n", ft_printf("self        | %c", x));
	printf("  | %d\n", printf("orig        | % c", x));
	printf("  | %d\n", ft_printf("self        | % c", x));
	printf("  | %d\n", printf("orig      20| %20c", x));
	printf("  | %d\n", ft_printf("self      20| %20c", x));
	printf("  | %d\n", printf("orig   20.15| %20.15c", x));
	printf("  | %d\n", ft_printf("self   20.15| %20.15c", x));
	printf("  | %d\n", printf("orig   15.20| %15.20c", x));
	printf("  | %d\n", ft_printf("self   15.20| %15.20c", x));
	printf("  | %d\n", printf("orig     -20| %-20c", x));
	printf("  | %d\n", ft_printf("self     -20| %-20c", x));
	printf("  | %d\n", printf("orig    -.20| %-.20c", x));
	printf("  | %d\n", ft_printf("self    -.20| %-.20c", x));
	printf("  | %d\n", printf("orig  -20.15| %-20.15c", x));
	printf("  | %d\n", ft_printf("self  -20.15| %-20.15c", x));
	printf("  | %d\n", printf("orig  -15.20| %-15.20c", x));
	printf("  | %d\n", ft_printf("self  -15.20| %-15.20c", x));
	printf("  | %d\n", printf("orig     020| %020c", x));
	printf("  | %d\n", ft_printf("self     020| %020c", x));
	printf("  | %d\n", printf("orig    0.20| %0.20c", x));
	printf("  | %d\n", ft_printf("self    0.20| %0.20c", x));
	printf("  | %d\n", printf("orig  020.15| %020.15c", x));
	printf("  | %d\n", ft_printf("self  020.15| %020.15c", x));
	printf("  | %d\n", printf("orig  015.20| %015.20c", x));
	printf("  | %d\n", ft_printf("self  015.20| %015.20c", x));
	printf("  | %d\n", printf("orig    -020| %-020c", x));
	printf("  | %d\n", ft_printf("self    -020| %-020c", x));
	printf("  | %d\n", printf("orig -020.15| %-020.15c", x));
	printf("  | %d\n", ft_printf("self -020.15| %-020.15c", x));
	printf("  | %d\n", printf("orig -015.20| %-015.20c", x));
	printf("  | %d\n", ft_printf("self -015.20| %-015.20c", x));
}

void	test_string(char *x)
{
	printf("============================================\n");
	printf("================ STRING TEST ===============\n");
	printf("============================================\n");
	printf("  | %d\n", printf("orig        | %s", x));
	printf("  | %d\n", ft_printf("self        | %s", x));
	printf("  | %d\n", printf("orig        | % s", x));
	printf("  | %d\n", ft_printf("self        | % s", x));
	printf("  | %d\n", printf("orig      20| %20s", x));
	printf("  | %d\n", ft_printf("self      20| %20s", x));
	printf("  | %d\n", printf("orig   20.15| %20.15s", x));
	printf("  | %d\n", ft_printf("self   20.15| %20.15s", x));
	printf("  | %d\n", printf("orig   15.20| %15.20s", x));
	printf("  | %d\n", ft_printf("self   15.20| %15.20s", x));
	printf("  | %d\n", printf("orig     -20| %-20s", x));
	printf("  | %d\n", ft_printf("self     -20| %-20s", x));
	printf("  | %d\n", printf("orig    -.20| %-.20s", x));
	printf("  | %d\n", ft_printf("self    -.20| %-.20s", x));
	printf("  | %d\n", printf("orig  -20.15| %-20.15s", x));
	printf("  | %d\n", ft_printf("self  -20.15| %-20.15s", x));
	printf("  | %d\n", printf("orig  -15.20| %-15.20s", x));
	printf("  | %d\n", ft_printf("self  -15.20| %-15.20s", x));
	printf("  | %d\n", printf("orig     020| %020s", x));
	printf("  | %d\n", ft_printf("self     020| %020s", x));
	printf("  | %d\n", printf("orig    0.20| %0.20s", x));
	printf("  | %d\n", ft_printf("self    0.20| %0.20s", x));
	printf("  | %d\n", printf("orig  020.15| %020.15s", x));
	printf("  | %d\n", ft_printf("self  020.15| %020.15s", x));
	printf("  | %d\n", printf("orig  015.20| %015.20s", x));
	printf("  | %d\n", ft_printf("self  015.20| %015.20s", x));
	printf("  | %d\n", printf("orig    -020| %-020s", x));
	printf("  | %d\n", ft_printf("self    -020| %-020s", x));
	printf("  | %d\n", printf("orig -020.15| %-020.15s", x));
	printf("  | %d\n", ft_printf("self -020.15| %-020.15s", x));
	printf("  | %d\n", printf("orig -015.20| %-015.20s", x));
	printf("  | %d\n", ft_printf("self -015.20| %-015.20s", x));
}

void	test_dig(int x)
{
	printf("============================================\n");
	printf("=============== DIGITAL TEST ===============\n");
	printf("============================================\n");
	printf("  | %d\n", printf("orig        | %d", x));
	printf("  | %d\n", ft_printf("self        | %d", x));
	printf("  | %d\n", printf("orig   space| % d", x));
	printf("  | %d\n", ft_printf("self   space| % d", x));
	printf("  | %d\n", printf("orig  space0| % 0d", x));
	printf("  | %d\n", ft_printf("self  space0| % 0d", x));
	printf("  | %d\n", printf("orig +space0| % 0d", x));
	printf("  | %d\n", ft_printf("self +space0| % 0d", x));
	printf("  | %d\n", printf("orig       2| %2d", x));
	printf("  | %d\n", ft_printf("self       2| %2d", x));
	printf("  | %d\n", printf("orig      .2| %.2d", x));
	printf("  | %d\n", ft_printf("self      .2| %.2d", x));
	printf("  | %d\n", printf("orig      20| %20d", x));
	printf("  | %d\n", ft_printf("self      20| %20d", x));
	printf("  | %d\n", printf("orig   20.15| %20.15d", x));
	printf("  | %d\n", ft_printf("self   20.15| %20.15d", x));
	printf("  | %d\n", printf("orig   15.20| %15.20d", x));
	printf("  | %d\n", ft_printf("self   15.20| %15.20d", x));
	printf("  | %d\n", printf("orig     -20| %-20d", x));
	printf("  | %d\n", ft_printf("self     -20| %-20d", x));
	printf("  | %d\n", printf("orig    -.20| %-.20d", x));
	printf("  | %d\n", ft_printf("self    -.20| %-.20d", x));
	printf("  | %d\n", printf("orig  -20.15| %-20.15d", x));
	printf("  | %d\n", ft_printf("self  -20.15| %-20.15d", x));
	printf("  | %d\n", printf("orig  -15.20| %-15.20d", x));
	printf("  | %d\n", ft_printf("self  -15.20| %-15.20d", x));
	printf("  | %d\n", printf("orig     020| %020d", x));
	printf("  | %d\n", ft_printf("self     020| %020d", x));
	printf("  | %d\n", printf("orig    0.20| %0.20d", x));
	printf("  | %d\n", ft_printf("self    0.20| %0.20d", x));
	printf("  | %d\n", printf("orig  020.15| %020.15d", x));
	printf("  | %d\n", ft_printf("self  020.15| %020.15d", x));
	printf("  | %d\n", printf("orig  015.20| %015.20d", x));
	printf("  | %d\n", ft_printf("self  015.20| %015.20d", x));
	printf("  | %d\n", printf("orig    -020| %-020d", x));
	printf("  | %d\n", ft_printf("self    -020| %-020d", x));
	printf("  | %d\n", printf("orig -020.15| %-020.15d", x));
	printf("  | %d\n", ft_printf("self -020.15| %-020.15d", x));
	printf("  | %d\n", printf("orig -015.20| %-015.20d", x));
	printf("  | %d\n", ft_printf("self -015.20| %-015.20d", x));
}

int	main(void)
{
	setbuf(stdout, NULL);


	//char *line = "hello dude!";
	int x = -1234;
	//char a = 'X';
	//test_character(a);
	//test_string(line);
	//test_string("i dont know who write this long string");
	//test_string(NULL);
	//test_dig(x);
	//test_dig(-x);
	test_pointer(&x);



	/*
	printf("|%c\n", a);
	printf("-|%-c\n", a);
	printf("0|%0c\n", a);
	printf("|%5c\n", a);
	printf("-|%-5c\n", a);
	printf("0|%05c\n", a);
	printf("|%10.15c\n", a);
	printf("|%10.5c\n", a);
	printf("-|%-10.15c\n", a);
	printf("-|%-10.5c\n", a);
	printf("0|%010.15c\n", a);
	printf("0|%010.5c\n", a);
	/*
	/*
	printf("simple|%d\n", x);
	printf("space |% d\n", x);
	printf("   +  |%+d\n", x);
	printf("   -  |%-d\n", x);
	printf("   0  |%0d\n", x);
	printf("   #  |%#d\n", x);
	printf("width = 8\n");
	printf("simple|%8d\n", x);
	printf("space |% 8d\n", x);
	printf("   +  |%+8d\n", x);
	printf("   -  |%-8d\n", x);
	printf("   0  |%08d\n", x);
	printf("   #  |%#8d\n", x);
	printf("presicion = 8\n");
	printf("simple|%.8d\n", x);
	printf("space |% .8d\n", x);
	printf("   +  |%+.8d\n", x);
	printf("   -  |%-.8d\n", x);
	printf("   0  |%0.8d\n", x);
	printf("   #  |%#.8d\n", x);
	printf("width = 16 / presicion = 8\n");
	printf("simple|%16.8d\n", x);
	printf("space |% 16.8d\n", x);
	printf("   +  |%+16.8d\n", x);
	printf("   -  |%-16.8d\n", x);
	printf("   0  |%016.8d\n", x);
	printf("   #  |%#16.8d\n", x);
	printf("width = 8 / presicion = 16\n");
	printf("simple|%8.16d\n", x);
	printf("space |% 8.16d\n", x);
	printf("   +  |%+8.16d\n", x);
	printf("   -  |%-8.16d\n", x);
	printf("   0  |%08.16d\n", x);
	printf("   #  |%#8.16d\n", x);
	printf("combo\n");
	printf("space+-0#|% +-0#8.16d\n", x);
	printf("space+-0|% +-08.16d\n", x);
	printf("space+-#|% +-#8.16d\n", x);
	printf("space-0#|% +0#8.16d\n", x);
	printf("+-0#|% -0#8.16d\n", x);
	printf("space+-|%+-0#8.16d\n", x);
	printf("space+#|% +#8.16d\n", x);
	printf("space0#|% 0#8.16d\n", x);
	printf("-0#|%-0#8.16d\n", x);
	printf("+-0|%+-08.16d\n", x);
	*/
	/*
	printf("=== self ===\n");
	my = ft_printf("someone %c %s = %p what? %5%", 'X', line, &x);
	printf("\nlen = %d\n", my);
	printf("\n=== orig ===\n");
	rl = printf("someone %c %s = %p what? %5%", 'X', line, &x);
	printf("\nlen = %d\n", rl);
	printf("\n=== test ===\n");*/
	//ft_printf("%d\n", 10);
	//printf("%d\n", 10);
	/*printf("%#i\n", 10);
	printf("%#u\n", 10);
	printf("%#x\n", 100000000);
	printf("%#X\n", 100000000);
	printf("%#p\n", &x);
	printf("%#s\n", "&x");
	printf("%#c\n", 'x');
	printf("\n=== test ===\n");*/
	//ft_printf("%d\n", &x);
	//printf("  7d  |%7x\n", x);
	//ft_printf("  7d  |%7x\n", x);
	//printf(" .7d  |%.7x\n", x);
	//ft_printf(" .7d  |%.7x\n", x);
	//printf("10.7d |%10.7x\n", x);
	//ft_printf("10.7d |%10.7x\n", x);
	//printf("7.10d |%7.10x\n", x);
	//ft_printf("7.10d |%7.10x\n", x);
	/* zero shit
	printf("orig = %10.000000u\n", x);
	ft_printf("self = %10.0u\n", x);
	printf("orig = %10.0i\n", x);
	ft_printf("self = %10.0i\n", x);
	printf("orig = %10.0d\n", x);
	ft_printf("self = %10.0d\n", x);
	printf("orig = %10.0x\n", x);
	ft_printf("self = %10.0x\n", x);
	printf("\n\n");
	*/
	return (0);
}

//      gcc main.c ft_printf.c func/*.c src/*.c && ./a.out
