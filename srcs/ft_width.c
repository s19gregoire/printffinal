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

void ft_align_right(t_print *mytab)
{
	if (mytab->zero && !mytab->point)
	{
		if (mytab->sign)
			write(1, "-", 1);
		while (mytab->zero && --mytab->width > -1 && !mytab->precision)
			write(1, "0", 1);
	}
	else if (!mytab->dash)
	{
			while (--mytab->width > -1)
				write(1, " ", 1);
			if (mytab->sign)
				write(1, "-", 1);
	}
	while (--mytab->precision > -1)
			write(1, "0", 1);
}

void ft_align_left(t_print *mytab)
{
	if (mytab->dash)
	{
		while (mytab->zero && --mytab->precision > -1)
			write(1, "0", 1);
		while (--mytab->width > -1)
			write(1, " ", 1);
	}
}

void ft_right_justify(t_print *mytab, int len)
{
	if (mytab->zero == 1)
		while (mytab->width-- > len)
			write(1, "0", 1);
	else
	{
		if (mytab->precision && mytab->precision < len)
			while (mytab->width-- > mytab->precision)
				write(1, " ", 1);
		else
		{
			while (mytab->width-- > len)
				write(1, " ", 1);
		}
	}
}

void ft_left_justify(t_print *mytab, int len)
{
		if (mytab->zero == 1)
			while (mytab->width-- > len)
				write(1, "0", 1);
		else
			while (mytab->width-- > len)
				write(1, " ", 1);
}

int ft_eval_width(t_print *mytab, const char *format, int pos)
{
	int i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	mytab->width = i;
	if (format[pos] == '.')
		pos = ft_eval_precision(mytab, format, pos);
	return (pos);
}
