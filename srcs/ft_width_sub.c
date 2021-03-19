/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:16:18 by gregoire          #+#    #+#             */
/*   Updated: 2021/03/19 14:16:43 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_align_right(t_print *mytab, int len)
{
	if (!mytab->dash && mytab->width >= mytab->precision)
	{
		if (mytab->zero == 1 || mytab->width == mytab->precision)
			while (mytab->width-- > len)
				write(1, "0", 1);
		else
		{
			while (mytab->width-- > len && mytab->width >= mytab->precision)
				write(1, " ", 1);
			while (mytab->precision-- > len)
				write(1, "0", 1);
		}
	}
	else
	{
		mytab->width -= mytab->precision;
		while (mytab->precision-- > len)
			write(1, "0", 1);
	}
}
