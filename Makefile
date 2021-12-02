SRC_DIR	=	./srcs
OBJ_DIR	=	./objs

SRCS	=	${SRC_DIR}/ps_main.c \
			${SRC_DIR}/ps_show.c \
			${SRC_DIR}/ps_utils.c \
			${SRC_DIR}/ps_stackargv.c \
			${SRC_DIR}/ps_error.c


OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o  ${addprefix ${OBJ_DIR}/, ${notdir ${<:.c=.o}}}

all:	${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${addprefix ${OBJ_DIR}/, ${notdir ${OBJS}}}

clean:
	${RM} ${addprefix ${OBJ_DIR}/, ${notdir ${OBJS}}}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

leak:
	valgrind --leak-check=full ./${NAME} 12 65 78 45 32 98 0
	valgrind --leak-check=full ./${NAME} 12 65 78 45lol 32 98 0
	valgrind --leak-check=full ./${NAME} 12 65 78 12 32 98 0
	valgrind --leak-check=full ./${NAME} 12
