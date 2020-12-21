# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:17:11 by sadolph           #+#    #+#              #
#    Updated: 2020/12/21 23:02:20 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := gcc
CFLAGS := #-Wall -Wextra -Werror

# Directories
INC_HERE := philo_one.h
UTILS_DIR := ./utils/
UTILS_NAME := libut.a
LINK_INC := -I$(UTILS_DIR)
LINK_LIB := -L$(UTILS_DIR) -lut

# Sources
NAME := philo_one
SRC :=					\
philo_one.c				\
life_cycle.c			\


all: $(NAME)

$(NAME): $(UTILS_NAME) $(INC_HERE)
	$(CC) $(CFLAGS) -o $@ $(LINK_INC) $(LINK_LIB) $(SRC)

$(UTILS_NAME):
	make -C $(UTILS_DIR)
