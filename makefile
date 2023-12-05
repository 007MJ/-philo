# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:23:00 by mnshimiy          #+#    #+#              #
#    Updated: 2023/12/04 15:18:30 by mnshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAG = -Wall -Werror -Wextra -pthread -g 

RM  = rm -fr

SRCS  = src/main.c src/create.c src/parsing/ft_atoi.c src/utils/routine.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS)  $(CFLAG) -o $@

%.o : %.c
	$(CC) $(CFLAG) -o $@ -c $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

