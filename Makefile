# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:17:11 by sadolph           #+#    #+#              #
#    Updated: 2020/12/23 18:41:58 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
INC_HERE := philo_one.h
UTILS_DIR := ./utils/
INC_DIR := $(UTILS_DIR) ./
UTILS_NAME := libut.a
LINK_INC := $(addprefix -I, $(INC_DIR))
LINK_LIB := -L$(UTILS_DIR) -lut

# Sources
NAME := philo_one
SRC :=					\
philo_one.c				\
life_cycle.c			\

all: $(UTILS_NAME) $(NAME)

$(NAME): $(UTILS_DIR)$(UTILS_NAME) $(INC_HERE) $(SRC)
	$(CC) $(CFLAGS) -o $@ $(LINK_INC) $(LINK_LIB) $(SRC)

$(UTILS_NAME):
	make -C $(UTILS_DIR)

# Standard rules
clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
