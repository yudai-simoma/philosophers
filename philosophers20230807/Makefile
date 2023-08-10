NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC_DIR	=	./src
OBJ_DIR	=	./obj
INCLUDE	=	-I$(SRC_DIR)

SRCS	=	\

OBJS	=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS	=	$(OBJS:.o=.d)
RM		=	rm -rf

.DEFAULT_GOAL = all
all		:	$(NAME)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

$(OBJ_DIR)/%.o : %.c
	mkdir -p ./obj
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -o $@ -c $<

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re