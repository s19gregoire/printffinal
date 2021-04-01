/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_ft_eval_witdh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:30:04 by gneve             #+#    #+#             */
/*   Updated: 2021/04/01 14:36:24 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_eval_width(t_print *tab, const char *format, int pos)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	tab->wdt = i;
	if (format[pos] == '.')
		pos = ft_eval_precision(tab, format, pos);
	return (pos);
}

void	ft_left_cs(t_print *tab, int len)
{
	while (tab->zero && tab->wdt-- > len)
		tab->tl += write(1, "0", 1);
	while (!tab->zero && tab->wdt-- > len)
		tab->tl += write(1, " ", 1);
}
