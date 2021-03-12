/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/12 13:48:31 by gregoire         ###   ########.fr       */
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
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	mytab->precision = i;
	//printf("prec %d\n", mytab->precision);
	return (pos);
}
