/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/02 17:30:13 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_fill_width(t_print *mytab, int len)
{

	mytab->total_length += mytab->width;
	if (mytab->zero == 1)
		while (mytab->width-- > len)
			write(1, "0", 1);
	else
		while (mytab->width-- > len)
			write(1, " ", 1);
}

int ft_len(int num)
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

int ft_eval_width(t_print *mytab, const char *format, int pos)
{
	int i;

	i = ft_atoi(&format[pos]);
	mytab->width = i;
	pos += ft_len(i);
	return (pos);
}
