# ******** VARIABLES ******** #

# ---- Final Lib --- #

NAME			=	libnlx.a

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	include/

# ---- Libs variables ---- #

MLX_PATH		=	minilibx_linux/

MLX_A			=	${MLX_PATH}libmlx.a

# ---- Files ---- #

HEADERS_LIST	=	nlx_color.h		\
					nlx_img.h		\
					nlx_line.h		\
					nlx_matrix.h	\
					nlx_vec.h		\
					nlx_win.h

SRCS_LIST		=	nlx_img.c		\
					nlx_line.c		\
					nlx_matrix.c	\
					nlx_win.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CFLAGS			=	-Wall -Wextra -Werror

# ---- Commands ---- #

RMF =	 		rm -f

MKDIR = 		mkdir -p

# ********* RULES ******** #

all:			${DIR_OBJS}
				make -C ${MLX_PATH}
				make ${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS}
					cp ${MLX_PATH}libmlx.a ${NAME}
					ar rcs ${NAME} ${OBJS}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o: ${DIR_SRCS}%.c ${HEADERS} ${MLX_A}
				cc ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:	 Makefile
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

clean:
				${RMF} ${OBJS}


fclean:			clean
				${RMF} ${NAME}

re:				fclean
				${MAKE} all

.PHONY:			all debug clean fclean re
