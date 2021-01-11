# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:19:19 by sadolph           #+#    #+#              #
#    Updated: 2021/01/11 19:29:06 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
OBJ_DIR := ./obj/
SRC_DIR := ./src/
INC_DIR := ./includes/
LINK_INC := $(addprefix -I, $(INC_DIR))

# Sources
NAME := libutils.a
SRC :=					\
ft_itoa.c				\
ft_atoi.c				\
ft_strlen.c				\
ft_putstr_fd.c			\
ft_putnbr_fd.c			\
ft_mysleep.c			\
OBJ := ${SRC:.c=.o}
O_WITH_DIR := $(addprefix $(OBJ_DIR), $(OBJ))


all: $(NAME)

$(NAME): $(O_WITH_DIR)
	ar rc $@ $?
	@echo "\033[32m$(NAME) successfully created\033[0m" ✅

# ВЫСТАВИТЬ ЗАВИСИМОСТИ ОТ ХЭДЭРОВ!!!
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LINK_INC) -c $< -o $@

# Standard rules
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
