# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 10:44:00 by adzahrao          #+#    #+#              #
#    Updated: 2024/11/08 05:08:05 by adzahrao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_printf.c ft_printf_ft.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all : $(NAME)

.o:.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean re