# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:19:19 by sadolph           #+#    #+#              #
#    Updated: 2020/12/21 23:10:01 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := gcc
CFLAGS := #-Wall -Wextra -Werror

# Directories
OBJ_DIR := ./obj/
INC := utils.h

# Sources
NAME := libut.a
SRC :=					\
ft_itoa.c				\
ft_atoi.c				\
ft_strlen.c				\
ft_putstr_fd.c			\
ft_putnbr_fd.c			\
ft_strjoin.c			\
ft_mysleep.c			\

OBJ := ${SRC:.c=.o}
O_WITH_DIR := $(addprefix $(OBJ_DIR), $(OBJ))


all: $(NAME)

$(NAME): $(O_WITH_DIR)
	ar rc $@ $^
	@echo "\033[32m$(NAME) successfully created\033[0m" ✅

$(OBJ_DIR)%.o: %.c $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Standard rules
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
