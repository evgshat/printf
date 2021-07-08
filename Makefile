parsing_srcs := parser_dot.c new_parser_flags.c parser_width.c parser_zero.c parser_minus.c init_flag.c parser_end.c write_before_perc.c
SRCS_P := $(addprefix parsing/, $(parsing_srcs))

types_srcs := c.c p.c s.c
SRCS_T := $(addprefix types/, $(types_srcs))

types_srcs_d := d.c write_d_s_res.c res_for_d size_d.c write_d_ch.c
SRCS_T_d := $(addprefix types/d/, $(types_srcs_d))

types_srcs_d_wp := d_w_and_p.c d_posit.c d_negat.c
SRCS_T_d_wp := $(addprefix types/d/d_wp/, $(types_srcs_d_wp))

types_srcs_d_w := d_only_w.c
SRCS_T_d_w := $(addprefix types/d/d_w/, $(types_srcs_d_w))

types_srcs_x := x_wp.c x.c
SRCS_T_x := $(addprefix types/x/, $(types_srcs_x))

types_srcs_big_x := big_x_wp.c big_x.c
SRCS_T_big_x := $(addprefix types/big_x/, $(types_srcs_big_x))

types_srcs_u := u.c res_for_u.c u_only_w.c u_w_and_p.c
SRCS_T_u := $(addprefix types/u/, $(types_srcs_u))

dic_srcs := dictionary_from_d_to_big_x.c dictionary_from_d_to_x.c is_type.c
SRCS_D := $(addprefix dictionaries/, $(dic_srcs))

SRCS := errors.c \
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
processor.c \
size_of_d.c \
size_of_x.c \
sum.c \
write_for_s.c \
write_s_null.c \
write_s.c \
ft_isdigit.c \
main.c

OBJS_P = $(SRCS_P:.c=.o)
OBJS_T = $(SRCS_T:.c=.o)
OBJS_T_d = $(SRCS_T_d:.c=.o)
OBJS_T_d_wp = $(SRCS_T_d_wp:.c=.o)
OBJS_T_d_w = $(SRCS_T_d_w:.c=.o)
OBJS_T_x = $(SRCS_T_x:.c=.o)
OBJS_T_big_x = $(SRCS_T_big_x:.c=.o)
OBJS_T_u = $(SRCS_T_u:.c=.o)
OBJS_D = $(SRCS_D:.c=.o)
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra -c -g
CC = gcc

RM = rm -rf

HEADER = -I ft_printf.h

.c.o:
	$(CC) $(CFLAGS) $< ${HEADER} -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_P) $(OBJS_T) $(OBJS_T_d) $(OBJS_T_d_wp) $(OBJS_T_d_w) $(OBJS_T_x) $(OBJS_T_big_x) $(OBJS_T_u) $(OBJS_D)
	ar rcs $(NAME) $(OBJS) $(OBJS_P) $(OBJS_T) $(OBJS_T_d) $(OBJS_T_d_wp) $(OBJS_T_d_w) $(OBJS_T_d_w) $(OBJS_T_x) $(OBJS_T_big_x) $(OBJS_T_u) $(OBJS_D)

clean:
	$(RM) $(OBJS) $(OBJS_P) $(OBJS_T) $(OBJS_T_d) $(OBJS_T_d_wp) $(OBJS_T_d_w) $(OBJS_T_x) $(OBJS_T_big_x) $(OBJS_T_u) $(OBJS_D)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
