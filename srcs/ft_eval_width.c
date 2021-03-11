/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/11 10:19:54 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_fill_width_right(t_print *mytab, int len)
{
	mytab->total_length += mytab->width - len;
	if (mytab->zero == 1)
		while (mytab->width-- > len)
			write(1, "0", 1);
	else
		while (mytab->width-- > len)
			write(1, " ", 1);
}

void	ft_fill_width_left(t_print *mytab, int len)
{
	mytab->total_length += mytab->width;
	if (mytab->zero == 1)
		while (mytab->width-- > len)
			write(1, "0", 1);
	else
		while (mytab->width-- > len)
			write(1, " ", 1);
}

int		ft_len(int num)
{
	int i;

	i = 0;
	if (num == 0)
		return (i);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int		ft_eval_width(t_print *mytab, const char *format, int pos)
{
	int i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	mytab->width = i;
	return (pos);
}
