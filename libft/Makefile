# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <babodere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 15:38:38 by babodere          #+#    #+#              #
#    Updated: 2025/05/21 06:11:50 by babodere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_putchar_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_substr.c \
		ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c \
		ft_itoa.c ft_strtrim.c utils.c ft_puthex.c ft_printf.c \
		get_next_line.c get_next_line_utils.c ft_strcmp.c

OBJS = $(SRCS:%.c=${OBJS_DIR}%.o)

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS_DIR = .objs/

CREATE_OBJS_DIR = mkdir -p $(OBJS_DIR)

BONUS_OBJS = $(BONUS:%.c=${OBJS_DIR}%.o)

INCLUDES = .

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = libft.a

${OBJS_DIR}%.o: %.c
	@${CREATE_OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean 
	rm -f $(NAME)
	
re: fclean all
