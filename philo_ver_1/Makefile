# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:12:11 by yshimoma          #+#    #+#              #
#    Updated: 2023/05/03 12:30:01 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS_DIR = ./src
SRCS = main.c utils.c thread.c action.c action_utils.c time.c\
	ft_atoi.c ft_isdigit.c
vpath %.c ${SRCS_DIR}
OBJ_DIR = ./obj
OBJS = ${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

all: ${NAME}

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