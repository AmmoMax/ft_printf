# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 19:20:40 by amayor            #+#    #+#              #
#    Updated: 2020/07/24 19:20:40 by amayor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .PHONY: all clean fclean re

NAME = libftprintf.a
COMPILER = clang
ARCHIVER = ar rc
LIBFT_DIR = libft
LIBFT_PATH = libft/libft.a
RANLIB  = ranlib
SRCS_FILES = ft_init_flags.c\
			ft_parse_char_string.c\
			ft_parse_flags.c\
			ft_parse_hex.c\
			ft_parse_int.c\
			ft_parse_isspec.c\
			ft_parse_pointer.c\
			ft_parse_string.c\
			ft_parse_unsigned.c\
			ft_printf.c\
			ft_utils.c
HEADER_FILE = ft_printf.h
HEADER_FILE_DIR = .
FLAGS = -c -Wall -Wextra -Werror
OBJECT_FILES = $(SRCS_FILES:.c=.o)

override OBJ_ALL ?= $(OBJECT_FILES)

all: $(NAME)

$(NAME): $(OBJ_ALL) $(HEADER_FILE)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_PATH) $(NAME)
	@$(ARCHIVER) $(NAME) $(OBJ_ALL)
	@$(RANLIB) $(NAME)
	@echo "[INFO] Library [$(NAME)] is created!"

%.o: %.c
	$(COMPILER) $(FLAGS) -I $(HEADER_FILE_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJECT_FILES)
	@echo "[INFO] Object files is removed: [$(OBJECT_FILES)]"

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@echo "[INFO] Library [$(NAME)] is removed!"

re: fclean all
