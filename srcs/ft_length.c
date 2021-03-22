/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 14:00:39 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_update_total_length_string(char *s, t_print *mytab, int len)
{
	if (s)
		len = ft_strlen(s);
	if (!s)
	{
		if (mytab->width > 6)
			mytab->total_length += mytab->width;
		else
			mytab->total_length += 6;
		return (len);
	}
	if (mytab->precision && len > mytab->precision)
		len = mytab->precision;
	if	((s && mytab->point && mytab->width) || (mytab->width >= mytab->precision && mytab->width > len))
		mytab->total_length += mytab->width;
	else
		mytab->total_length += len;
	return (len);
}

void	ft_update_mytab(t_print *mytab, int len)
{
	if (mytab->sign)
	{
		mytab->total_length += 1;
		if (mytab->width)
			mytab->width -= 1;
	}
	if (mytab->width && mytab->width >= mytab->precision)
	{
		mytab->total_length += mytab->width;
		if (mytab->precision > len)
			mytab->precision -= len;
		else
			mytab->precision = 0;
		if (!mytab->is_zero)
			mytab->width = mytab->width - mytab->precision - len;
	}
	else if (mytab->precision > mytab->width)
	{
		mytab->total_length += mytab->precision;
		mytab->width = 0;
		mytab->precision -= len;
	}
	else
		mytab->total_length += len;
}
