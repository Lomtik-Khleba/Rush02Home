# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/29 10:39:34 by rbarber           #+#    #+#              #
#    Updated: 2020/08/30 15:18:25 by rbarber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02

SRCS	= srcs/*.c

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

${NAME}:
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			/bin/rm -f *.o

fclean:	clean
			/bin/rm -f ${NAME}

re:		fclean all
