/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:30:05 by mlazzare          #+#    #+#             */
/*   Updated: 2021/02/27 11:36:00 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_print
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
int ft_eval_width(t_print *mytab, const char *format, int pos);
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

# endif