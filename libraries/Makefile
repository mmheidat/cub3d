# Variables
SRCS = get_next_line.c get_next_line_utils.c utils.c utils2.c utils4.c utils3.c \
       ft_printf.c ft_parser.c ft_putnums.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
