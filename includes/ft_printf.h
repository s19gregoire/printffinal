/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:30:05 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 10:01:19 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <stdarg.h>
#	include <stdio.h>
#	include <limits.h>
#	include "libft.h"

typedef struct	s_print
{
	char		type;
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			point;
	int			star;
	int			dash;
	int			is_neg;
	int			left_aligned;
	int			right_aligned;
	int			special_chars;
	int			position;
	int			flag_chars;
	int			total_length;
	int 		sign;
	int			is_zero;
}					t_print;

int	ft_printf(const char *format, ...);
int ft_percentage_check(const char *format, int pos);
int ft_eval_width(t_print *mytab, const char *format, int pos);
int ft_eval_precision(t_print *mytab, const char *format, int pos);
int	ft_eval_flag(t_print *mytab, const char *format, int pos);
int ft_signed_int(char *s);
int	ft_unsigned_int(char *s);
int ft_eval_input(t_print *mytab, const char *format, int pos);
int ft_eval_variable(t_print *mytab, const char *format, int pos);
int ft_eval_dash(t_print *mytab, const char *format, int pos);
int ft_eval_zero(t_print *mytab, const char *format, int pos);
int ft_eval_star(t_print *mytab, const char *format, int pos);
int ft_output_char(t_print *mytab, const char *format, int pos);
int ft_output_string(t_print *mytab, const char *format, int pos);
int ft_output_int(t_print *mytab, const char *format, int pos);
int ft_output_unsigned_int(t_print *mytab, const char *format, int pos);
int ft_output_hexa_int(t_print *mytab, const char *format, int pos);
int ft_output_pointer(t_print *mytab, const char *format, int pos);
//void ft_write_variable(t_print mytab, const char *format, int pos);
t_print *ft_initialise_tab(t_print *mytab);
void ft_update_char_counts(t_print *mytab, int pos);
int convert_to_hex(int nb);
void	ft_putchar(char c);
char		*ft_unsigned_itoa(unsigned int nb);
int	n_len(long n);
int ft_len(int num);
void ft_align_right(t_print *mytab);
void ft_align_left(t_print *mytab);
void ft_write_null(t_print *mytab);
void ft_update_mytab(t_print *mytab, int len);
void ft_left_justify(t_print *mytab, int len);
void ft_right_justify(t_print *mytab, int len);
int ft_update_total_length_string(char *s, t_print *mytab, int len);
int ft_write_str_with_point(t_print *mytab, int pos);
int ft_check_sign(t_print *mytab, int j);

#	endif
