NAME	=	libftprintf.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c src/checks.c src/format_c.c src/format_d_i.c src/format_p.c\
			src/format_percent.c src/format_s.c src/format_u.c src/format_x.c\
			src/parsing.c src/values.c src/writers.c func/ft_atoi.c func/ft_isdigit.c\
			func/ft_puthex.c func/ft_putnbr_u.c func/ft_putnbr.c func/ft_putpoint.c\
			func/str_null_len.c

OBJ		=	${SRC:.c=.o}

RM		=	rm -f

.c.o:
		${CC} ${FLAGS} -c $< -I . -o ${<:.c=.o}

${NAME}:	${OBJ}
		ar rcs ${NAME} $?

all:		${NAME}

bonus:	re

clean:
		${RM} ${OBJ} ${OBJB}

fclean:		clean
		${RM} ${NAME}

re:		fclean	all

.PHONY:	all	clean	fclean	re	bonus
