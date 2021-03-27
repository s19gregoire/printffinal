/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/25 17:59:23 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_output_pointer(t_print *tab)
{
	unsigned long long j;

	j = va_arg(tab->args, unsigned long long);

	if (!j)
	{
		if (tab->prc < 0)
			ft_write_null(tab, "0x0");
		else
			ft_write_null(tab, "(nil)");
		return ;
	}
	ft_update_tab(tab, 14);
	ft_right_idupx(tab);
	tab->tl += write(1, "0x", 2);
	tab->tl += ft_putnbr_base(j, "0123456789abcdef");
	ft_left_idupx(tab);
}

