/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/19 14:40:36 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_output_pointer(t_print *tab, int pos)
{
	unsigned long long j;

	j = va_arg(tab->args, unsigned long long);

	if (!j)
	{
		if (tab->wdt < 0)
			ft_write_null(tab, "0x0");
		else
			ft_write_null(tab, "(nil)");
		return (pos);
	}
	ft_update_tab(tab, 14);
	ft_right_idupx(tab);
	tab->tl += write(1, "0x", 2);
	tab->tl += ft_putnbr_base_unsigned(j, "0123456789abcdef");
	ft_left_idupx(tab);
	return (pos);
}
