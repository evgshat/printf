SRCS := big_x.c \
c.c \
d.c \
dictionary_from_d_to_big_x.c \
dictionary_from_d_to_x.c \
errors.c \
from_d_to_big_x.c \
from_d_to_p.c \
from_d_to_x.c \
ft_atoi.c \
ft_itoa_unint.c \
ft_itoa.c \
ft_printf.c \
ft_strjoin.c \
ft_strlen.c \
over_percision.c \
over_width_zero.c \
over_width.c \
p.c \
parser_dot.c \
processor_type.c \
parser_flags.c \
parser_width.c \
processor.c \
s.c \
size_of_d.c \
size_of_x.c \
sum.c \
u.c \
write_for_s.c \
write_s.c \
x.c

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
