# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 11:15:15 by yshimoma          #+#    #+#              #
#    Updated: 2023/04/29 14:54:07 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS_DIR = ./src
SRCS = main.c thread.c action.c time.c\
	ft_atoi.c ft_isdigit.c
vpath %.c ${SRCS_DIR}
OBJ_DIR = ./obj
OBJS = ${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
CC = cc
CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror -g
RM = -rf

all: ${NAME}

${OBJS}: philosophers.h

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ./obj
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re