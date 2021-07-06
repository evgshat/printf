parsing_srcs := parser_flags.c parser_dot.c new_parser_flags.c
SRCS_P := $(addprefix parsing/, $(parsing_srcs))

types_srcs := c.c d.c big_x.c p.c s.c u.c x.c
SRCS_T := $(addprefix types/, $(types_srcs))

SRCS := dictionary_from_d_to_big_x.c \
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
processor_type.c \
parser_width.c \
processor.c \
size_of_d.c \
size_of_x.c \
sum.c \
write_for_s.c \
write_s_null.c \
write_s.c \

OBJS_P = $(SRCS_P:.c=.o)
OBJS_T = $(SRCS_T:.c=.o)
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra -c
CC = gcc

RM = rm -rf

HEADER = -I ft_printf.h

.c.o:
	$(CC) $(CFLAGS) $< ${HEADER} -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_P) $(OBJS_T)
	ar rcs $(NAME) $(OBJS) $(OBJS_P) $(OBJS_T)

clean:
	$(RM) $(OBJS) $(OBJS_P) $(OBJS_T)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
