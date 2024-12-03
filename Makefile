GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf

CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIB_FLAGS = -lmlx -lm -lXext -lX11

INC =   -I ./inc \
		-I $(LIBDIRS)libft/	\
		-I $(LIBDIRS)printf/inc	\
		-I $(LIBDIRS)get_next_line

SOURCES_DIR = ./src/
OBJECTS_DIR = ./obj/

SOURCES = $(wildcard $(SOURCES_DIR)*.c) $(wildcard $(SOURCES_DIR)**/*.c)
OBJECTS = $(patsubst $(SOURCES_DIR)%, $(OBJECTS_DIR)%, $(SOURCES:.c=.o))

# $(info SOURCES: $(SOURCES))
# $(info OBJECTS: $(OBJECTS))

# libraries
LIBDIRS = ./lib/

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = $(LIBDIRS)libft/

PRINTF = $(PRINTF_DIR)libftprintf.a
PRINTF_DIR = $(LIBDIRS)printf/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = $(LIBDIRS)minilibx/

GNL = $(GNL_DIR)*line.c $(GNL_DIR)*utils.c
GNL_DIR = $(LIBDIRS)get_next_line/

GITHUB_URL = https://raw.githubusercontent.com/dmitrijslasko/fdf42/d2d31f6ccc2dad88bdb2bcf6cb05aa5ed044f248/assets/images/start.xpm
DOWNLOAD_DIR = ./assets/images

all: $(LIBFT) $(PRINTF) $(MINILIBX) $(NAME) $(DOWNLOAD_DIR)/start.xpm

$(DOWNLOAD_DIR)/start.xpm: $(DOWNLOAD_DIR)
	@curl -s -L $(GITHUB_URL) -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(NAME) $(GNL) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) \
			-L$(PRINTF_DIR) -lftprintf $(LIB_FLAGS)
	@echo "\n$(GREEN)$(NAME) got successfully compiled.$(RESET)"

$(DOWNLOAD_DIR):
	@mkdir -p $(DOWNLOAD_DIR)

$(OBJECTS): $(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@
	@echo "$(GREEN)%%%%$(RESET)\c"

clean:
	rm -f $(OBJECTS_DIR)**/*.o
	rm -rf $(OBJECTS_DIR)*
	rm -rf $(DOWNLOAD_DIR)
	@echo "$(GREEN)clean complete\n$(RESET)\c"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(GREEN)fclean complete\n$(RESET)\c"

re: fclean all

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

.PHONY: all clean fclean re
