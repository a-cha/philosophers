# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadolph <sadolph@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 22:17:11 by sadolph           #+#    #+#              #
#    Updated: 2021/01/11 23:36:26 by sadolph          ###   ########.fr        #
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
NAME := philo_one
SRC :=					\
main.c					\
init_philos.c			\
life_cycle.c			\
print_status.c			\
check_die.c				\
OBJ := ${SRC:.c=.o}
O_WITH_DIR := $(addprefix $(OBJ_DIR), $(OBJ))

all: $(UTILS_NAME) $(NAME)

$(NAME): $(UTILS_DIR)$(UTILS_NAME) $(O_WITH_DIR)
	$(CC) $(CFLAGS) -o $@ $(LINK_INC) $(LINK_LIB) $(SRC)

$(UTILS_NAME):
	make -C $(UTILS_DIR)

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
