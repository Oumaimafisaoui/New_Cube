CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Imlx -Ofast -ffast-math 

SRC =  	parsingcub3d/libft/ft_split.c \
		parsingcub3d/libft/ft_splitnewline.c\
		parsingcub3d/libft/ft_strcmp.c \
		parsingcub3d/libft/ft_substr.c \
		parsingcub3d/libft/ft_atoi.c \
		parsingcub3d/libft/ft_strlen.c \
		parsingcub3d/libft/ft_strcpy.c \
		parsingcub3d/libft/ft_strdup.c \
		parsingcub3d/libft/ft_isdigit.c \
		parsingcub3d/get_next_line/get_next_line.c \
		parsingcub3d/get_next_line/get_next_line_utils.c \
		parsingcub3d/cub3d.c \
		parsingcub3d/cub3d_utils.c \
		parsingcub3d/compass_colore.c \
		parsingcub3d/counters.c \
		parsingcub3d/parser.c \
		parsingcub3d/dividingmap.c \
		parsingcub3d/checkzero.c \
		parsingcub3d/parsetwopartsofmap.c \
		parsingcub3d/norm.c \
		main.c \
		ray_tools.c\
		tools_casting.c\
		cub3d_outils.c draw_minimap.c init.c move_player.c dda.c check_walls.c \
		three_d.c \
		dda_tools.c \
		draw_tools.c \
		init_tools.c \
		ray_tools_suite.c \
		dda_tools_suite.c  

OBJ = ${SRC:.c=.o}
NAME = cub3D
LIB  = header.h parsingcub3d/cub3d.h

all : ${NAME}

${NAME} : ${OBJ} ${LIB}
		${CC}  ${CFLAGS} ${OBJ}  -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		
%.o : %.c ${LIB}
	${CC} ${CFLAGS} -c $< -o $@
clean:
	${RM} ${OBJ}

fclean: clean
	${RM}  ${NAME}

re: fclean all

.PHONY: clean fclean re all