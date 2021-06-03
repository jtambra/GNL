#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtambra <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 21:58:04 by jtambra           #+#    #+#              #
#    Updated: 2021/06/03 22:37:37 by jtambra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = get_next_line

LIBFT_DIR = ./libft/

INC = -I./includes/ -I$(LIBFT_DIR)

LIBS = -L $(LIBFT_DIR) -lft

FLAGS = -g -Wall -Wextra -Werror -O3 $(INC) -MD -D BUFFER_SIZE=32

CC = gcc 

SRCS = main.c \
		$(addprefix ./srcs/,\
		get_next_line.c\
		get_next_line_utils.c)

OBJS = $(SRCS:.c=.o)
D_FILES = $(SRCS:.c=.d)


all: $(NAME)

debug: FLAGS += -fsanitize=address -g
debug: re

$(NAME): ${OBJS} | tools
		${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBS}
include $(wildcard $(D_FILES))

.c.o:
	${CC} ${FLAGS} -c $< -o $@

tools:
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

clean:
	rm -f ${OBJS} ${D_FILES}
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf ${NAME}
	make -C $(LIBFT_DIR) fclean

re: fclean all

