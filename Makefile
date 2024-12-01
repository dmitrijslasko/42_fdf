GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf

CC = cc
FLAGS = -Wall -Wextra -Werror -g
INC = -I ./inc
LIBRARIES = -lmlx -lm -lXext -lX11

SOURCES_DIR = ./src/
SOURCES := $(shell find $(SOURCES_DIR) -type f -name "*.c")

OBJECTS_DIR = ./obj/
OBJECTS = $(patsubst $(SOURCES_DIR)/%, $(OBJECTS_DIR)/%, $(SOURCES:.c=.o))

LIBDIRS = ./lib/

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./lib/libft/

PRINTF = $(PRINTF_DIR)libftprintf.a
PRINTF_DIR = ./lib/printf/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./lib/minilibx/

GNL = lib/get_next_line/*line.c lib/get_next_line/*utils.c
GNL_DIR = ./lib/get_next_line

all: $(LIBFT) $(PRINTF) $(MINILIBX) $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(NAME) $(GNL) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -L$(PRINTF_DIR) -lftprintf $(LIBRARIES)
	@echo "\n$(GREEN)$(NAME) got successfully compiled.$(RESET)"

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
