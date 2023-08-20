NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC_DIR	=	./src
OBJ_DIR	=	./obj

# find * -name "*.c" -and | sort | sed 's/$/ \\/'
SRCS	=	\
			action.c \
			init.c \
			libft/ft_atoi.c \
			libft/ft_isdigit.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_strlen.c \
			main.c \
			thread.c \
			utils.c \
			x_wrapper.c \

OBJS	=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS	=	$(OBJS:.o=.d)
RM		=	rm -rf

.DEFAULT_GOAL = all
all		:	$(NAME)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p OBJ_DIR
	mkdir -p $(OBJ_DIR)/libft
	$(CC) $(CFLAGS) -MMD -MP -o $@ -c $<

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re