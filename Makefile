NAME = push_swap

# SRCS = main.c error.c get_stack.c check_stack.c operations_a.c operations_b.c operations_ab.c\
# 		algorathms.c find_num.c

SRCS = main.c error.c get_stack.c check_stack.c operations_a.c operations_b.c operations_ab.c\
		lst_utils.c small_sort.c find_num.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re rm -f
