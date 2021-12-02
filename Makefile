SRC_DIR	=	./srcs
OBJ_DIR	=	./objs

SRCS	=	${SRC_DIR}/main.c


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
	${RM} ${OBJ_DIR}/${notdir ${SRCS}}
	${RM} ${OBJS}
