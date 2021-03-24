# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 11:33:03 by mlazzare          #+#    #+#              #
#    Updated: 2021/02/26 12:09:51 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCDIR	=	srcs/
OBJDIR	=	bin/
INCDIR	= includes/
LIBFTDIR	= libft/

mySRCS = \
	./srcs/ft_printf.c \
	./srcs/ft_eval_input.c \
	./srcs/ft_width.c \
	./srcs/ft_length.c \
	./srcs/ft_conversions.c \
	./srcs/ft_dash_and_star.c \
	./srcs/ft_output_char.c \
	./srcs/ft_output_int.c \
	./srcs/ft_output_unsigned_int.c \
	./srcs/ft_output_hexa_int.c \
	./srcs/ft_output_pointer.c \
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
