# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 11:33:03 by mlazzare          #+#    #+#              #
#    Updated: 2021/03/22 10:01:34 by gregoire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCDIR	=	srcs/
OBJDIR	=	bin/
INCDIR	= includes/
LIBFTDIR	= libft/

mySRCS = \
	./srcs/ft_printf.c \
	./srcs/ft_format.c \
	./srcs/ft_alignment.c \
	./srcs/ft_length.c \
	./srcs/ft_flags.c \
	./srcs/ft_output_char.c \
	./srcs/ft_output_int.c \
	./srcs/ft_output_unsigned.c \
	./srcs/ft_output_hexa.c \
	./srcs/ft_output_string.c \

HEADERS = \
	./includes/ft_printf.h \
	./includes/libft.h

SRC		:= $(notdir $(mySRCS)) # 				Files only
OBJ		:= $(SRC:.c=.o)	#					Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path

LIBFT		= $(LIBFTDIR)libft.a

CC			= gcc


CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -I$(INCDIR)

AR			= ar -rc

RM			= rm -f

VPATH = $(SRCDIR)

all:	$(LIBFT) $(NAME)

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(mySRCS) $(HEADERS) $(OBJS)
			$(AR) $(NAME) $(OBJS) $(LIBFTDIR)*.o

$(LIBFT):
			$(MAKE) -C $(LIBFTDIR)

clean:
			$(RM) -rf $(OBJDIR)
			$(MAKE) -C $(LIBFTDIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFTDIR) fclean

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re
