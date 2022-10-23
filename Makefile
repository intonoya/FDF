# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: intonoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 16:45:54 by intonoya          #+#    #+#              #
#    Updated: 2022/10/04 19:25:14 by intonoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

SRC				=	$(wildcard *.c)

LIBFT			=	libft/libft.a

OBJS			=	${SRC:.c=.o}

MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit -lm

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

.c.o			:
					${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS} ${LIBFT}
						${CC} ${CFLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME}	$(LIBFT) 

$(LIBFT)		:
					make -C libft

all				:	${NAME}

clean			:
					make clean -C libft
					@rm -rf ${OBJS}

fclean			:	clean
						@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
