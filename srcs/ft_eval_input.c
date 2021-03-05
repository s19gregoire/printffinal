/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/04 09:19:32 by gregoire         ###   ########.fr       */
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
	else if (format[pos] == 'x' || format[pos] == 'X')
		pos = ft_output_hexa_int(mytab, format, pos);
	return (pos);
}

int	ft_eval_precision(t_print *mytab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	(void)mytab;
	mytab->point = 1;
	if (ft_isdigit(format[pos]))
	{
		while (ft_isdigit(format[pos]))
			i = i * 10 + ft_atoi(&format[pos++]);
		mytab->precision = i;
		//pos += ft_len(i);
	}
	else
		mytab->precision = 0;
	return (pos);
}

int	ft_eval_input(t_print *mytab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos])))
	{
		// if (format[pos] == ' ' && format[pos + 1] == 's')
		// {
		// 	write(1, " ", 1);
		// 	pos++;
		// }
		if (format[pos] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		if (format[pos] == '-')
			pos = ft_eval_dash(mytab, format, pos);
		if (format[pos] == '.')
			pos = ft_eval_precision(mytab, format, pos);
		if (format[pos] == '*')
			pos = ft_eval_width(mytab, format, pos);
		if (format[pos] == '0')
		{
			mytab->zero = 1;
			pos++;
		}
		if (ft_isdigit(format[pos]))
			break ;
	}
	if (ft_isdigit(format[pos]))
		pos = ft_eval_width(mytab, format, pos);
	if (ft_isalpha(format[pos]))
		pos = ft_eval_variable(mytab, format, pos);
	//ft_update_total_length(mytab, pos);
	//printf("%d\n", mytab->total_length);
	return (pos);
}
