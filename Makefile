NAME	= so_long
BNS_N	=

SRC_N 	= so_long.c mapinit.c mapload.c
SRC_B 	=

DIR_SRC	= ./src/
DIR_BON	= ./bonus/
DIR_FTL	= ./ft_lib/
DIR_MLX = ./mlx/
INCPATH	= ${DIR_FTL} ${DIR_MLX} ${DIR_SRC} ${DIR_BON}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLXFLG = -L ${DIR_MLX} -lmlx -framework OpenGL -framework AppKit

SRCS_P	= ${addprefix ${DIR_SRC}, ${SRC_N}}
SRCS_B	= ${addprefix ${DIR_BON}, ${SRC_B}}

OBJ_P	= ${SRCS_P:.c=.o}
OBJ_B	= ${SRCS_B:.c=.o}

DPDS	= ${SRCS_P:.c=.d} ${SRCS_B:.c=.d}

all:	libft libmlx ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -MMD -c $< -o $@  -I"${INCPATH}"

include ${wildcard ${DPDS}}

libft:
	${MAKE} -C ${DIR_FTL}

libmlx:
	${MAKE} -C ${DIR_MLX}

${NAME}: ${DIR_FTL}libft.a ${DIR_MLX}libmlx.a ${OBJ_P}
	${CC} ${CFLAGS} -o $@ ${OBJ_P} -L ${DIR_FTL} -lft ${MLXFLG}

${BNS_N}: ${DIR_FTL}libft.a ${OBJ_B}
	${CC} ${CFLAGS} -o $@ ${OBJ_B}  -L${DIR_FTL} -lft ${MLXFLG}

debug:
	${MAKE} libmlx
	${MAKE} CFLAGS="${CFLAGS} -g3" libft
	${MAKE} CFLAGS="${CFLAGS} -g3" ${NAME}

bonus: libft ${BNS_N}

clean:
	${RM} ${OBJ_P} ${OBJ_B} ${DPDS}
	${MAKE} -C ${DIR_FTL} clean
	${MAKE} -C ${DIR_MLX} clean

fclean:	clean
	${RM} ${NAME} ${BNS_N}
	${MAKE} -C ${DIR_FTL} fclean

re:	fclean all

.PHONY: all bonus clean fclean re debug libft libmlx
