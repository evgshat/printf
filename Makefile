SRCS := parser_dot.c \
parser_flags.c \
parser_width.c \
processor.c \
errors.c \
d.c \
ft_itoa.c \
c.c \
s.c \
ft_strlen.c



OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra -c
CC = gcc

RM = rm -rf

HEADER = -I libft.h ft_printf.h

.c.o:
	$(CC) $(CFLAGS) $< ${HEADER} -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
