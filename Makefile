processor_srcs := processor.c processor_type.c
SRCS_PR := $(addprefix processor/, $(processor_srcs))

parsing_srcs := parser_dot.c new_parser_flags.c parser_width.c parser_zero.c init_flag.c write_before_perc.c parser_end.c
SRCS_P := $(addprefix parsing/, $(parsing_srcs))

types_srcs := c.c perc.c
SRCS_T := $(addprefix types/, $(types_srcs))

types_srcs_d := d.c write_d_s_res.c res_for_d size_d.c write_d_ch.c
SRCS_T_d := $(addprefix types/d/, $(types_srcs_d))

types_srcs_d_wp := d_w_and_p.c d_posit.c d_negat.c
SRCS_T_d_wp := $(addprefix types/d/d_wp/, $(types_srcs_d_wp))

types_srcs_d_w := d_only_w.c
SRCS_T_d_w := $(addprefix types/d/d_w/, $(types_srcs_d_w))

types_srcs_x := x_wp.c x.c from_d_to_x.c size_of_x.c
SRCS_T_x := $(addprefix types/x/, $(types_srcs_x))

types_srcs_big_x := big_x_wp.c big_x.c from_d_to_big_x.c
SRCS_T_big_x := $(addprefix types/big_x/, $(types_srcs_big_x))

types_srcs_u := u.c res_for_u.c u_only_w.c u_w_and_p.c
SRCS_T_u := $(addprefix types/u/, $(types_srcs_u))

types_srcs_s :=  s.c write_s.c write_s_null.c write_for_s.c res_for_s.c s_wp.c s_less_wp.c s_over_w.c s_over_wp.c
SRCS_T_s := $(addprefix types/s/, $(types_srcs_s))

types_srcs_p :=  p.c from_d_to_p.c p_wp.c size_of_p.c
SRCS_T_p := $(addprefix types/p/, $(types_srcs_p))

dic_srcs := dictionary_from_d_to_big_x.c dictionary_from_d_to_x.c is_type.c
SRCS_D := $(addprefix dictionaries/, $(dic_srcs))

SRCS :=  ft_atoi.c \
ft_itoa_unint.c \
ft_itoa.c \
ft_printf.c \
ft_strjoin.c \
ft_strlen.c \
over_percision.c \
over_width_zero.c \
over_width.c \
sum.c \
ft_isdigit.c \
itoa_for_p.c

OBJS = $(SRCS:.c=.o) $(SRCS_PR:.c=.o) $(SRCS_P:.c=.o) $(SRCS_T:.c=.o) $(SRCS_T_d:.c=.o) \
$(SRCS_T_d_wp:.c=.o) $(SRCS_T_d_w:.c=.o) $(SRCS_T_x:.c=.o) $(SRCS_T_big_x:.c=.o) \
$(SRCS_T_u:.c=.o) $(SRCS_T_s:.c=.o) $(SRCS_T_p:.c=.o) $(SRCS_D:.c=.o)

NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra -c -g
CC = gcc

RM = rm -rf

HEADER = ft_printf.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -I ${HEADER} -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
