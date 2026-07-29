NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# 1. Automatically find ALL .c files in the project directory
SRCS        = $(wildcard *.c)

# 2. Convert all found .c names to .o names
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re