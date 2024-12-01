# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 15:03:30 by dmlasko           #+#    #+#              #
#    Updated: 2024/07/26 15:07:26 by dmlasko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
FT_PRINTF_SRCS = 		ft_printf.c			\
				src/ft_parse_flags.c		\
				src/ft_process_data_type.c	\
				src/ft_putchar_new.c		\
				src/ft_putnbr_base.c		\
				src/ft_putptr_base.c		\
				src/ft_putstr_new.c		\
				src/ft_utils.c			\
				src/ft_itoa_base.c
						
FT_PRINTF_OBJS = 		$(FT_PRINTF_SRCS:.c=.o)
FT_PRINTF_NAME = 		libftprintf.a

# LIBFT SOURCES
LIBFT_NAME = 			libft.a
LIBFT_SRCS_DIR = 		libft
LIBFT_INCLUDES_DIR = 		libft
LIBFT_SRCS = 			$(shell find $(LIBFT_SRCS_DIR) -name "ft_*.c")
LIBFT_OBJS = 			$(LIBFT_SRCS:.c=.o)

# LIBRARY NAME
NAME = 				libftprintf.a

# COMPILER AND f
CC = 				cc
#Cf = 				-Wall -Wextra -Werror -I$(LIBFT_INCLUDES_DIR) -I.

# COMPILING
%.o: %.c
	$(CC) $(Cf) -c $< -o $@

all: $(NAME)

$(NAME): $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(FT_PRINTF_OBJS) $(LIBFT_OBJS)

bonus: $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(FT_PRINTF_OBJS) $(LIBFT_OBJS)

clean:
	rm -f $(FT_PRINTF_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(FT_PRINTF_NAME) $(LIBFT_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus