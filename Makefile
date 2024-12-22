# Checking OS type
UNAME_S         = $(shell uname -s)

# Executable and compilation
NAME            = cub3d

SRC_DIR         = ./src/functions/
INCLUDES_DIR    = ./Includes
LIBFT_LIB       = ./libraries/libft.a
LIBFT_LIB_DIR   = ./libraries
MLX_LIB         = ./mlx/libmlx.a
MLX_LIB_DIR     = ./mlx

SRCS            = cub3d.c \
                  game/ft_game_init.c \
                  game/ft_key_handler.c \
                  game/ft_move.c \
                  parsing/ft_args_checker.c \
                  parsing/ft_floodfill.c \
                  parsing/ft_parser.c \
                  parsing/ft_scan.c \
                  parsing/ft_tx_parser.c \
                  ray/ft_drawer.c \
                  ray/ft_raycaster.c \
                  utils/ft_floodfill_utils.c \
                  utils/ft_free_utils.c \
                  utils/ft_mlx_utils.c \
                  utils/ft_other_utils.c \
                  utils/ft_parser_utils.c

OBJ_DIR         = ./objs/
OBJS            = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g -I $(INCLUDES_DIR) -fsanitize=address
RM              = rm -rf

# Object file compilation rule
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "Compiling $<..."
	@mkdir -p $(@D) # Ensures the directory exists
	@$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Executable target (macOS specific linking)
ifeq ($(UNAME_S),Darwin)
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_LIB_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_LIB)
	@echo "$(NAME) compiled successfully."
endif

# Build libft
$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_LIB_DIR)

# Build mlx
$(MLX_LIB):
	@$(MAKE) -C $(MLX_LIB_DIR)

# Cleaning rules
clean:
	@$(MAKE) clean -C $(LIBFT_LIB_DIR)
	@$(MAKE) clean -C $(MLX_LIB_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "Objects cleaned successfully."

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_LIB_DIR)
	@$(RM) $(NAME)
	@echo "Project cleaned successfully."

re: fclean all

.PHONY: all clean fclean re
