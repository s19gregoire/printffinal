/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 14:12:12 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_align_right(t_print *mytab)
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

void	ft_align_left(t_print *mytab)
{
	if (mytab->dash)
	{
		while (mytab->zero && --mytab->precision > -1)
			write(1, "0", 1);
		while (--mytab->width > -1)
			write(1, " ", 1);
	}
}

void	ft_right_justify(t_print *mytab, int len)
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

void	ft_left_justify(t_print *mytab, int len)
{
	if (mytab->zero == 1)
		while (mytab->width-- > len)
			write(1, "0", 1);
	else
		while (mytab->width-- > len)
			write(1, " ", 1);
}

int	ft_len(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (i);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}
