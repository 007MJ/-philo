# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:23:00 by mnshimiy          #+#    #+#              #
#    Updated: 2023/12/08 16:38:34 by mnshimiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAG = -Wall -Werror -Wextra -pthread -g -fsanitize=thread
# fsanitize=thread

RM  = rm -fr

SRCS  = src/main.c src/create.c \
		src/utils/routine.c  src/utils/ft_calloc.c src/utils/c_thread.c \
		src/parsing/ft_atoi.c src/parsing/is_digit.c  src/parsing/main_parsing.c \

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

