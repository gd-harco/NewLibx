# ******** VARIABLES ******** #

# ---- Final Lib --- #

NAME			=	libnlx.a

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Libs variables ---- #

MLX_PATH		=	minilibx_linux/

MLX_A			=	${MLX_PATH}libmlx.a

# ---- Files ---- #

HEADERS_LIST	=	nlx_color.h			\
					nlx_draw.h			\
					nlx_img.h			\
					nlx_line.h			\
					nlx_mat.h			\
					nlx_vec.h			\
					nlx_win.h

SRCS_LIST		=	nlx_clipping.c		\
					nlx_draw_util.c		\
					nlx_draw.c			\
					nlx_img.c			\
					nlx_line.c			\
					nlx_mat.c			\
					nlx_mat_multiply.c	\
					nlx_mat_rot.c		\
					nlx_mat_trans.c		\
					nlx_mat_world.c		\
					nlx_win.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CFLAGS			=	-Wall -Werror -Wextra -g3

# ---- Commands ---- #

RMF =	 		rm -f

MKDIR = 		mkdir -p

# ********* RULES ******** #

all				:
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
