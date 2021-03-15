/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/02 16:05:56 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_update_total_length_string(char *s, t_print *mytab, int len)
{
	if (s)
		len = ft_strlen(s);
	if (!s && mytab->point)
	{
		mytab->total_length += mytab->width;
		return (len); //+= o solo =?
	}
	if (mytab->precision && len > mytab->precision)
		len = mytab->precision;
	if ((s && mytab->point && mytab->width) || (mytab->width >= mytab->precision && mytab->width > len))
		mytab->total_length += mytab->width;
	else
		mytab->total_length += len;
	return (len);
}

void ft_update_total_length(t_print *mytab, int len)
{
	if (mytab->width >= mytab->precision)
		mytab->total_length += mytab->width;
	else if (mytab->precision > mytab->width)
		mytab->total_length += mytab->precision;
	else
		mytab->total_length += len;
}
