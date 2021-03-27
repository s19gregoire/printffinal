/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/26 11:51:17 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int 	ft_eval_variable(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_output_char(tab);
	else if (format[pos] == 's')
		ft_output_string(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_output_int(tab);
	else if (format[pos] == 'u')
		ft_output_unsigned_int(tab);
	else if (format[pos] == 'p')
		ft_output_pointer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		ft_output_hexa_int(tab, format[pos] - 23);
	return (pos);
}

int ft_eval_input(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos])))
	{
		if (format[pos] == ' ')
		{
			tab->tl += write(1, " ", 1);
			pos++;
		}
		if (format[pos] == '%')
		{
			ft_percentage(tab);
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
	ft_reset_tab(tab);
	return (pos);
}
