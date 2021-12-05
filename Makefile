#	Compilation setting

NAME	=	push_swap

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror


#	Directories

DIR_SRC	=	./srcs
DIR_OBJ	=	./objs
DIR_INC	=	./headers/


#	Sources

SRCS	=	${DIR_SRC}/ps_main.c \
			${DIR_SRC}/ps_show.c \
			${DIR_SRC}/ps_utils.c \
			${DIR_SRC}/ps_stackargv.c \
			${DIR_SRC}/ps_error.c

OBJS	=	${addprefix ${DIR_OBJ}/, ${notdir ${SRCS:.c=.o}}}

HEADER	=	push_swap.h


#	DO NOT CHANGE

RM		=	rm -f

vpath %.c ${DIR_SRC}

all : ${NAME}

${NAME}:	${OBJS}
	${CC} ${FLAGS} -o ${NAME}  ${OBJS}

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
	${CC} ${CFLAGS} -I ${DIR_INC} -o $@ -c $^

${DIR_OBJ} :
	@mkdir -p ${DIR_OBJ}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all


leak:
	valgrind --leak-check=full ./${NAME} 12 65 78 45 32 98 0
	valgrind --leak-check=full ./${NAME} 12 65 78 45lol 32 98 0
	valgrind --leak-check=full ./${NAME} 12 65 78 12 32 98 0
	valgrind --leak-check=full ./${NAME} 12

norm:
	norminette ${SRCS}
	norminette ${HEADER}
