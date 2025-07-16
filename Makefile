NAME := cub3d
CC := cc

# Define libft directory
LIBFT_DIR := ./libft
LIBFT_DIR = ./libft
LIBMLX_DIR = ./libs/mlx
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
LIBFT := ./libft/libft.a
#----------mac ---------
CFLAGS = -Werror -Wextra -Wall -I$(LIBMLX_DIR)/include/MLX42 -I$(LIBFT_DIR) -I./$(INC_DIR)
# DEBUG_FLAGS = -Werror -Wextra -Wall -I$(LIBMLX_DIR)/include/MLX42 -I$(LIBFT_DIR) -I./$(INC_DIR) -fsanitize=address -g

#---------linux---------

SOURCE_DIR = ./src
INIT_DIR = ./src/init
PARSE_DIR = ./src/parse

INC_DIR = inc
OBJ_DIR = obj

VPATH = $(SOURCE_DIR):$(INIT_DIR):$(PARSE_DIR)


# ---------- Subjects ---------- #
MY_SOURCES = \
        test_main.c \
        main.c \
        init.c \
		error.c \
		exit.c


HEADERS = \
		$(INC_DIR)/cub3d.h \
		$(INC_DIR)/error.h \
        $(INC_DIR)/init.h \
        $(INC_DIR)/parse.h

OBJ 	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))


all: $(LIBFT) $(LIBMLX) $(NAME)
$(LIBMLX):
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX_DIR)
	cd $(LIBMLX_DIR) && git checkout ce254c3a19af8176787601a2ac3490100a5c4c61
	cmake $(LIBMLX_DIR) -B$(LIBMLX_DIR)/build && cmake --build $(LIBMLX_DIR)/build
$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@ -L$(LIBMLX_DIR)/build -lmlx42 -lglfw -lm -pthread

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C ./libft


clean:
	@rm -rf $(OBJ_DIR)
	@if [ -d "./libft" ]; then make -C libft clean; fi

.PHONY: re clean fclean all libft_fclean

libft_fclean:
	@if [ -d "./libft" ]; then make -C libft fclean; fi

fclean: clean libft_fclean
	@rm -f $(NAME)
	@rm -rf $(LIBMLX_DIR)

re: fclean
	$(MAKE) all
