# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 10:43:03 by amayor            #+#    #+#              #
#    Updated: 2020/05/27 13:12:24 by amayor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

COMPILER = clang
ARCHIVER = ar rc
NAME = libft.a
RANLIB  = ranlib
SRCS_FILES = 	ft_isalpha.c \
				ft_isdigit.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_putstr_len.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_substr.c \
				ft_tolower.c
HEADER_FILE = libft.h
HEADER_FILE_DIR = .
FLAGS = -c -Wall -Wextra -Werror
OBJECT_FILES = $(SRCS_FILES:.c=.o)

override OBJ_ALL ?= $(OBJECT_FILES)

all: $(NAME)

$(NAME): $(OBJ_ALL) $(HEADER_FILE)
	@$(ARCHIVER) $(NAME) $(OBJ_ALL)
	@$(RANLIB) $(NAME)
	@echo "[INFO] Library [$(NAME)] is created!"

%.o: %.c
	$(COMPILER) $(FLAGS) -I $(HEADER_FILE_DIR) -c $< -o $@

clean:
	@rm -f $(OBJECT_FILES)
	@echo "[INFO] Object files is removed: [$(OBJECT_FILES)]"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft.so
	@echo "[INFO] Library [$(NAME)] is removed!"

re: fclean all