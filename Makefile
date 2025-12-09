NAME = push_swap
TEST = test

TEST_FILES = tests.c utils.c get_stack.c check_stack.c operations_a.c operations_b.c operations_ab.c\
		algorathms.c find_num.c
SRCS = main.c utils.c get_stack.c check_stack.c operations_a.c operations_b.c operations_ab.c\
		algorathms.c find_num.c

TEST_OBJS = $(TEST_FILES:.c=.o)
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# // TEST RULE //
$(TEST): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_OBJS) $(LIBFT) -o test

clean:
	rm -f $(OBJS)
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re rm -f
