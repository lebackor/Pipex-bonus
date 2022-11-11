# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 15:32:59 by lebackor          #+#    #+#              #
#    Updated: 2022/11/11 17:00:17 by lebackor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_split.c\
			srcs/ft_strcmp.c\
			srcs/ft_strjoin.c\
			srcs/ft_strlen.c\
			srcs/ft_substr.c\
			srcs/ft_printf.c\
			srcs/ft_printf_utils.c\
			srcs/ft_putchar.c\
			srcs/ft_putnbr.c\
			srcs/ft_putstr.c\
			srcs/ft_putstr_fd.c\
			pipex.c\
			parsing.c\
			cleaning.c\
			multipipex.c\
			multichilds.c \
			liste.c \

OBJS = ${SRCS:.c=.o}

CC	=	gcc

CFLAGS = -Wall -Werror -Wextra -g3

NAME = pipex

all : ${NAME}

${NAME} :	${OBJS}
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Ca arrive..."

%.o: %.c
	@${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

clean :
		rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
