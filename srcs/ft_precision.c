/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/02/26 10:55:39 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_eval_zero(t_print *mytab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	mytab->zero = 1;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	mytab->width = i;
	return (pos);
}

int ft_eval_precision(t_print *mytab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	mytab->point = 1;
	while (format[pos] == '0')
		pos++;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
		mytab->precision = i;
	}
	if (format[pos] == '*')
	{
		pos = ft_eval_star(mytab, format, pos);
	}
	return (pos);
}
