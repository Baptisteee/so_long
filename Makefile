# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <babodere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 00:11:35 by babodere          #+#    #+#              #
#    Updated: 2025/05/23 00:16:58 by babodere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRCS := so_long.c parsing.c parsing2.c vector.c

SRC_DIR := src

FLAGS := -Wall -Wextra -Werror -MP -MMD -ggdb
INCLUDES := -Llibft -lft 
BUILD_ROOT := build
BUILD_DIR := $(BUILD_ROOT)

DEPS := $(SRCS:%.c=$(BUILD_DIR)/%.d)
OBJS := $(SRCS:%.c=%.o)

MAKE_LIBFT := $(MAKE) -C libft
LIBFT := libft/libft.a

MAKE_MINILIBX := $(MAKE) -C minilinx-linux
MINILIBX := minilibx-linux/libmlx.a

all: $(NAME)

-include $(DEPS)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS:%=$(BUILD_DIR)/%)
	cc ${CFLAGS} $(OBJS:%=$(BUILD_DIR)/%) -o $@ $(INCLUDES)

$(MINILIBX):
	$(MAKE_MINILIBX) all

$(LIBFT):
	$(MAKE_LIBFT) all

re: fclean all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	cc $(FLAGS) -c -o $@ $< -Ilibft

clean:
	@$(MAKE_LIBFT) $@
	@rm -rf $(BUILD_ROOT)

fclean: clean
	@$(MAKE_LIBFT) $@
	@rm -rf $(NAME)

bonus: all

.PHONY: all bonus fclean clean re

