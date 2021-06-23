SRCS := parser_dot.c \
parser_flags.c \
parser_width.c \
processor.c \
errors.c \
d.c \
ft_itoa.c \
c.c \
s.c \
ft_strlen.c \
big_x.c \
dictionary_from_d_to_big_x.c \
dictionary_from_d_to_x.c \
from_d_to_big_x.c \
from_d_to_x.c \
ft_itoa.c \
ft_strlen.c \
over_percision.c \
over_width.c \
size_for_d.c \
write_for_s.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra -c
CC = gcc

RM = rm -rf

HEADER = -I ft_printf.h

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
