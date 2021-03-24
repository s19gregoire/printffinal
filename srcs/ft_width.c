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

void ft_right_idupx(t_print *tab)
{
	if (tab->zero && !tab->pnt)
	{
		if (tab->sign)
			write(1, "-", 1);
		while (!tab->prc && --tab->wdt > -1)
			write(1, "0", 1);
	}
	else if (!tab->dash)
	{
			while (--tab->wdt > -1)
				write(1, " ", 1);
			if (tab->sign)
				write(1, "-", 1);
	}
	while (--tab->prc > -1)
			write(1, "0", 1);
}

void ft_left_idupx(t_print *tab)
{
	if (tab->dash)
	{
		while (tab->dash && tab->zero && --tab->prc > -1)
			write(1, "0", 1);
		while (tab->dash && --tab->wdt > -1)
			write(1, " ", 1);
	}
}

void ft_right_cs(t_print *tab, int len)
{
	while (tab->zero && tab->wdt-- > len)
		write(1, "0", 1);
	if (!tab->zero && tab->prc && tab->prc < len)
		while (tab->wdt-- > tab->prc)
			write(1, " ", 1);
	else
		while (!tab->zero && tab->wdt-- > len)
			write(1, " ", 1);
}

void ft_left_cs(t_print *tab, int len)
{
	while (tab->zero && tab->wdt-- > len)
		write(1, "0", 1);
	while (!tab->zero && tab->wdt-- > len)
		write(1, " ", 1);
}


