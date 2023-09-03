# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 10:55:14 by yshimoma          #+#    #+#              #
#    Updated: 2023/09/03 14:21:41 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC_DIR		=	./src
OBJ_DIR		=	./obj
LIBFT_DIR	=	./libft
INCLUDE		=	-Iinclude -Ilibft


# (
#   find src -type f -name "*.c" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/'
#   find libft -type f -name "*.c" | sort | sed 's/^libft\//\${LIBFT_DIR}\//;s/$/ \\/'
# )
SRCS	=	\
			main.c \
			${SRC_DIR}/error/is_error.c \
			${SRC_DIR}/init/main_thread_init.c \
			${SRC_DIR}/thread/thread.c \
			${SRC_DIR}/utils/ft_putendl.c \
			${SRC_DIR}/utils/ft_putstr.c \
			${SRC_DIR}/utils/ft_putstr_error.c \
			${SRC_DIR}/utils/set_current_time.c \
			${LIBFT_DIR}/ft_atoi.c \
			${LIBFT_DIR}/ft_isdigit.c \
			${LIBFT_DIR}/ft_strlen.c \

OBJS	=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS	=	${OBJS:.o=.d}
RM		=	rm -rf

.DEFAULT_GOAL = all
all		:	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

${OBJ_DIR}/%.o : %.c
	mkdir -p $(@D)
	${CC} ${CFLAGS} ${INCLUDE} -MMD -MP -o $@ -c $<

clean	:
	${RM} ${OBJ_DIR}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re