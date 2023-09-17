# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 10:55:14 by yshimoma          #+#    #+#              #
#    Updated: 2023/09/17 17:25:17 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

SRC_DIR		=	./src
OBJ_DIR		=	./obj
LIBFT_DIR	=	./libft
INCLUDE		=	-Iinclude -Ilibft


# (
#   find src -type f -name "*.c" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/'
#   find libft -type f -name "*.c" | sort | sed 's/^libft\//\${LIBFT_DIR}\//;s/$/ \\/'
# ) | pbcopy
SRCS	=	\
			main.c \
			${SRC_DIR}/action/has_fork.c \
			${SRC_DIR}/action/has_forks_even_philosopher.c \
			${SRC_DIR}/action/has_forks_odd_philosopher.c \
			${SRC_DIR}/action/start_eating.c \
			${SRC_DIR}/action/start_sleeping.c \
			${SRC_DIR}/error/is_args_error.c \
			${SRC_DIR}/init/main_thread_init.c \
			${SRC_DIR}/init/philo_thread_init.c \
			${SRC_DIR}/thread/create_philo_thread.c \
			${SRC_DIR}/thread/create_thread.c \
			${SRC_DIR}/thread/is_program_stopped.c \
			${SRC_DIR}/thread/is_program_stopped_main.c \
			${SRC_DIR}/thread/is_program_stopped_philo.c \
			${SRC_DIR}/thread/print_message.c \
			${SRC_DIR}/thread/print_message_main.c \
			${SRC_DIR}/thread/print_message_philo.c \
			${SRC_DIR}/thread/wait_for_thread.c \
			${SRC_DIR}/time_utils/get_time_diff.c \
			${SRC_DIR}/time_utils/set_current_time.c \
			${SRC_DIR}/utils/ft_putendl.c \
			${SRC_DIR}/utils/ft_putstr.c \
			${SRC_DIR}/utils/ft_putstr_error.c \
			${SRC_DIR}/x_wrapper/ft_xpthread_mutex_lock.c \
			${SRC_DIR}/x_wrapper/ft_xpthread_mutex_unlock.c \
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

# Test rule
test: CFLAGS += -fsanitize=thread
test: re

-include ${DEPS}

.PHONY: all clean fclean re