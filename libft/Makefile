# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneve <gneve@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 18:36:32 by gneve             #+#    #+#              #
#    Updated: 2021/04/01 09:53:13 by gneve            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = ./

SRC	=	ft_strlen.c				\
		ft_atoi.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_substr.c				\
		ft_split.c				\
		ft_itoa.c				\
		ft_itoa_base.c				\
		ft_numlen_base.c				\
		ft_putnbr_base.c				\
		ft_putchar.c			\

OBJS = $(SRC:%.c=%.o)

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -c -I$(INCLUDES)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)


all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
