NAME	= so_long
BNS_N	=

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC_N 	= so_long.c mapload.c
SRC_B 	=

DIR_SRC	= ./src/
DIR_BON	= ./bonus/
DIR_FTL	= ./ft_lib/
INCPATH	= ${DIR_FTL} ${DIR_SRC} ${DIR_BON}

SRCS_P	= ${addprefix ${DIR_SRC}, ${SRC_N}}
SRCS_B	= ${addprefix ${DIR_BON}, ${SRC_B}}

OBJ_P	= ${SRCS_P:.c=.o}
OBJ_B	= ${SRCS_B:.c=.o}

DPDS	= ${SRCS_P:.c=.d} ${SRCS_B:.c=.d}

all:	libft ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -MMD -c $< -o $@  -I"${INCPATH}"

include ${wildcard ${DPDS}}

libft:
	${MAKE} -C ${DIR_FTL}

${NAME}: ${DIR_FTL}libft.a ${OBJ_P}
	${CC} ${CFLAGS} -o $@ -L${DIR_FTL} ${OBJ_P} -lft

${BNS_N}: ${DIR_FTL}libft.a ${OBJ_B}
	${CC} ${CFLAGS} -o $@ -L${DIR_FTL} ${OBJ_B} -lft

debug:
	${MAKE} CFLAGS="${CFLAGS} -g3" all bonus

bonus: libft ${BNS_N}

clean:
	${RM} ${OBJ_P} ${OBJ_B} ${DPDS}
	${MAKE} -C ${DIR_FTL} clean

fclean:	clean
	${RM} ${NAME} ${BNS_N}
	${MAKE} -C ${DIR_FTL} fclean

re:	fclean all

.PHONY: all bonus clean fclean re debug libft
