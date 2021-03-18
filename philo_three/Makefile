# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:17:11 by sadolph           #+#    #+#              #
#    Updated: 2021/01/12 00:15:20 by sadolph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
UTILS_DIR := ../utils/
UTILS_NAME := libutils.a
OBJ_DIR := ./obj/
SRC_DIR := ./src/
INC_DIR := $(UTILS_DIR)includes ./includes
LINK_INC := $(addprefix -I, $(INC_DIR))
LINK_LIB := -L$(UTILS_DIR) -lutils

# Sources
NAME := philo_three
SRC :=						\
	check_die.c				\
	init_philos.c			\
	life_cycle.c			\
	ft_safety_exit.c		\
	main.c

OBJ := ${SRC:.c=.o}
DEP := ${SRC:.c=.d}
O_WITH_DIR := $(addprefix $(OBJ_DIR), $(OBJ))
D_WITH_DIR := $(addprefix $(OBJ_DIR), $(DEP))


all: $(UTILS_NAME) $(NAME)

$(NAME): $(O_WITH_DIR)
	$(CC) $(CFLAGS) -o $@ $(LINK_INC) $(LINK_LIB) $^
	@echo "\033[32m$(NAME)\033[0m successfully created" ✅

include $(D_WITH_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LINK_INC) -c $< -o $@ -MMD

$(UTILS_NAME):
	make -C $(UTILS_DIR)

# Standard rules
clean:
	rm -rf $(OBJ_DIR)
	make -C $(UTILS_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(UTILS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
