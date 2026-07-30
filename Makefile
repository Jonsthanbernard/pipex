# Name of the executable
NAME        = pipex

# Compiler and Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -Ilibrary/include

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = library

# Source Files and Object Files
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/child.c \
              $(SRC_DIR)/path.c \
              $(SRC_DIR)/utils.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Library Dependencies
LIBFT       = $(LIBFT_DIR)/libft.a

# Rules
all: $(NAME)

# Build the final executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Build Libft if not already built
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compile source files into object files inside obj/ directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

# Re-build everything
re: fclean all

.PHONY: all clean fclean re