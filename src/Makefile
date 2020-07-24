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

.PHONY: all clean fclean re

COMPILER = clang
ARCHIVER = ar rc
NAME = libft.a
RANLIB  = ranlib
SRCS_FILES = 
HEADER_FILE = libft.h
HEADER_FILE_DIR = .
FLAGS = -c -Wall -Wextra -Werror
OBJECT_FILES = $(SRCS_FILES:.c=.o)

BONUS_SRCS_FILES = 	
BONUS_OBJECT_FILES = $(BONUS_SRCS_FILES:.c=.o)

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
	@rm -f $(BONUS_OBJECT_FILES)
	@echo "[INFO] Object files is removed: [$(OBJECT_FILES)] and bonus: [$(BONUS_OBJECT_FILES)]"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft.so
	@echo "[INFO] Library [$(NAME)] is removed!"


bonus:
	@make OBJ_ALL="$(OBJECT_FILES) $(BONUS_OBJECT_FILES)" all
	@echo "[INFO] Bonus function is created and added to libft!"


re: fclean all

so:
	$(COMPILER) -fPIC -c -Wall -Wextra -Werror $(SRCS_FILES) $(BONUS_SRCS_FILES)
	$(COMPILER) -shared -o libft.so $(OBJECT_FILES) $(BONUS_OBJECT_FILES)