/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash_and_star.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 13:59:16 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_eval_dash(t_print *mytab, const char *format, int pos)
{
	pos++;
	mytab->dash = 1;
	while (format[pos] == '-')
		pos++;
	pos = ft_eval_width(mytab, format, pos);
	return (pos);
}

int	ft_eval_star(t_print *mytab, const char *format, int pos)
{
	pos++;
	mytab->star = 1;
	if (!mytab->point)
		mytab->width = va_arg(mytab->args, int);
	else
		mytab->precision = va_arg(mytab->args, int);
	if (format[pos] == '.')
	{
		mytab->point = 1;
		pos++;
	}
	if (ft_isdigit(format[pos]) || format[pos] == 0)
	{
		pos = ft_eval_precision(mytab, format, pos);
	}
	if (format[pos] == '*')
	{
		mytab->precision = va_arg(mytab->args, int);
		pos++;
	}
	return (pos);
}
