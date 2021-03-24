/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/02 16:53:13 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int 	ft_eval_variable(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		pos = ft_output_char(tab, format, pos);
	else if (format[pos] == 's')
		pos = ft_output_string(tab, format, pos);
	else if (format[pos] == 'd' || format[pos] == 'i')
		pos = ft_output_int(tab, format, pos);
	else if (format[pos] == 'u')
			pos = ft_output_unsigned_int(tab, format, pos);
	else if (format[pos] == 'p')
			pos = ft_output_pointer(tab, format, pos);
	else if (format[pos] == 'x')
			pos = ft_output_hexa_intm(tab, format, pos);
	else if (format[pos] == 'X')
			pos = ft_output_hexa_intx(tab, format, pos);
	return (pos);
}

int ft_eval_input(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos])))
	{
		if (format[pos] == '%')
		{
			tab->tl = write(1, "%", 1);
			break ;
		}
		if (format[pos] == '0')
			pos = ft_eval_zero(tab, format, pos);
		if (format[pos] == '*')
			pos = ft_eval_star(tab, format, pos);
		if (format[pos] == '-')
			pos = ft_eval_dash(tab, format, pos);
		if (format[pos] == '.')
			pos = ft_eval_precision(tab, format, pos);
		if (ft_isdigit(format[pos]))
			pos = ft_eval_width(tab, format, pos);
	}
	if (ft_isalpha(format[pos]))
		pos = ft_eval_variable(tab, format, pos);
	return (pos);
}
