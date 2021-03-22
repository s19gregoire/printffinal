/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 11:25:16 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_eval_variable(t_print *mytab, const char *format, int pos)
{
	if (format[pos] == 'c')
		pos = ft_output_char(mytab, format, pos);
	else if (format[pos] == 's')
		pos = ft_output_string(mytab, format, pos);
	else if (format[pos] == 'd' || format[pos] == 'i')
		pos = ft_output_int(mytab, format, pos);
	else if (format[pos] == 'u')
		pos = ft_output_unsigned_int(mytab, format, pos);
	else if (format[pos] == 'p')
		pos = ft_output_pointer(mytab, format, pos);
	if (format[pos] == 'x')
		pos = ft_output_hexa_intm(mytab, format, pos);
	else if (format[pos] == 'X')
		pos = ft_output_hexa_intx(mytab, format, pos);
	return (pos);
}

int	ft_eval_input(t_print *mytab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos])))
	{
		if (format[pos] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		if (format[pos] == '0')
			pos = ft_eval_zero(mytab, format, pos);
		if (format[pos] == '*' || (ft_isdigit(format[pos])))
			pos = ft_eval_width(mytab, format, pos);
		if (format[pos] == '-')
			pos = ft_eval_dash(mytab, format, pos);
		if (format[pos] == '.')
			pos = ft_eval_precision(mytab, format, pos);
		if (format[pos] == '*' || (ft_isdigit(format[pos])))
			pos = ft_eval_width(mytab, format, pos);
	}
	if (ft_isalpha(format[pos]))
		pos = ft_eval_variable(mytab, format, pos);
	return (pos);
}
