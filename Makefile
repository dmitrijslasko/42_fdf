GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = fdf

CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIB_FLAGS = -lmlx -lm -lXext -lX11

INC =   -I ./inc \
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

PRINTF = $(PRINTF_DIR)libftprintf.a
PRINTF_DIR = $(LIBDIRS)printf/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = $(LIBDIRS)minilibx/

GNL = $(GNL_DIR)*line.c $(GNL_DIR)*utils.c
GNL_DIR = $(LIBDIRS)get_next_line/

GITHUB_URL = https://raw.githubusercontent.com/dmitrijslasko/42-assets/7f5dcb0542c630bce507ce6b5cc2e258ef11ff31/intro.xpm
DOWNLOAD_DIR = ./assets/images/

all: submodule $(PRINTF) $(MINILIBX) $(NAME) $(DOWNLOAD_DIR)intro.xpm

$(DOWNLOAD_DIR)intro.xpm: $(DOWNLOAD_DIR)
	@curl -L $(GITHUB_URL) -o $@

$(DOWNLOAD_DIR):
	@mkdir -p $(DOWNLOAD_DIR)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(NAME) $(GNL) -L$(MINILIBX_DIR) \
			-L$(PRINTF_DIR) -lftprintf $(LIB_FLAGS)
	@echo "\n$(GREEN)$(NAME) got successfully compiled.$(RESET)"

$(OBJECTS): $(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@
	@echo "$(GREEN)%%%%$(RESET)\c"

submodule:
	@git submodule update --init --recursive

clean:
	rm -f $(OBJECTS_DIR)**/*.o
	rm -rf $(OBJECTS_DIR)*
	rm -rf $(DOWNLOAD_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	@echo "$(GREEN)clean complete\n$(RESET)\c"

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(PRINTF_DIR)
	@echo "$(GREEN)fclean complete\n$(RESET)\c"

re: fclean all

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

.PHONY: all clean fclean re submodule printf get_next_line minilibx
