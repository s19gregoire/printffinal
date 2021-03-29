/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/29 09:03:44 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_output_pointer(t_print *tab)
{
	unsigned long long j;
	int l;

	l = 2;
	j = va_arg(tab->args, unsigned long long);
	if (!(!j && tab->pnt))
		l += ft_numlen_base(j, 16);
	ft_update_tab(tab, l);
	ft_right_idupx(tab);
	tab->tl += write(1, "0x", 2);
	if (!(!j && tab->pnt))
		tab->tl += ft_putnbr_base(j, "0123456789abcdef");		
	ft_left_idupx(tab);
}

