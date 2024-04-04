SRCDIR	= ./src/
SRCNAME	= main.c parse.c allocate.c clean.c file.c str.c dict.c search.c search2.c
SRCS	= ${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=./include/
OBJS	= ${SRCS:.c=.o}
NAME	= rush-02
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror


.c.o:
			${CC} ${CFLAGS} -I ${INCDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all: 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}


.PHONY:		clean fclean all