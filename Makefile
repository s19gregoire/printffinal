NAME        = libftprintf.a

SRCS_PATH    = srcs/

LIBFT_PATH    = libft/

LIBFT_LIB    = libft.a

HEADERS_FOLDER    = includes/

SRCS_FILES    = \
./srcs/ft_printf.c \
./srcs/ft_eval_input.c \
./srcs/ft_width.c \
./srcs/ft_length.c \
./srcs/ft_precision.c \
./srcs/ft_dash_and_star.c \
./srcs/ft_output_char.c \
./srcs/ft_output_int.c \
./srcs/ft_output_unsigned_int.c \
./srcs/ft_output_hexa_int.c \
./srcs/ft_output_pointer.c \
./srcs/ft_output_string.c \

SRCS_OBJS     = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:		${SRCS_OBJS} pmake
						${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
						${LIBFTMAKE}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRCS_OBJS}

fclean: clean
	${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re
