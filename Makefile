SRCS := ft_memset.c \
ft_bzero.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

CFLAGS = -Werror -Wall -Wextra -c
CC = gcc

RM = rm -rf

HEADER = -I libft.h

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
