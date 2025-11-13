NAME = fractol

CC = cc

SRC_DIR = sources
OBJ_DIR = obj
BONUS_SRC_DIR = bonus/sources
BONUS_OBJ_DIR = obj_bonus
INC_DIR = include
BONUS_INC_DIR = bonus/include
MLX_DIR = minilibx-linux

MLX_LIB = $(MLX_DIR)/libmlx.a

SRCS = sources/atod.c \
	   sources/main.c \
	   sources/color.c \
	   sources/fractals.c \
	   sources/hooks.c \
	   sources/parser.c \
	   sources/render.c \
	   sources/zoom.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS = bonus/sources/main_bonus.c \
			 bonus/sources/color_bonus.c \
			 bonus/sources/fractals_bonus.c \
			 bonus/sources/hooks_bonus.c \
			 bonus/sources/parser_bonus.c \
			 bonus/sources/render_bonus.c \
			 bonus/sources/zoom_bonus.c
			 
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

BONUS_NAME = fractol_bonus

INCLUDES = -I$(INC_DIR) -I$(MLX_DIR)
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
BONUS_INCLUDES = -I$(BONUS_INC_DIR) -I$(INC_DIR) -I$(MLX_DIR)
BONUS_CFLAGS = -Wall -Wextra -Werror $(BONUS_INCLUDES)

LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


bonus: $(MLX_LIB) $(BONUS_OBJ_DIR) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	@$(CC) $(BONUS_CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BONUS_OBJ_DIR)
	@$(MAKE) -s -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

bonus_clean:
	@rm -rf $(BONUS_OBJ_DIR)
	@rm -f $(BONUS_NAME)

bonus_fclean: bonus_clean

re: fclean all

.PHONY: all clean fclean re bonus bonus_clean bonus_fclean
