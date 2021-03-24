/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexa_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 11:26:39 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_output_hexa_intm(t_print *tab, const char *format, int pos)
{
	// int		i;
	unsigned long long		j;
	int len;

	// i = 0;
	len = 0;
	j = va_arg(tab->args, long long);
	(void)format;
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	len = ft_len(j);
	if (len >= 10)
		len = 8;
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	len = ft_putnbr_base(j, "0123456789abcdef");
	ft_left_idupx(tab);
	if (len > tab->wdt)
		tab->tl = len;
	else
		tab->tl = tab->wdt;
	return (pos);
}

int	ft_output_hexa_intx(t_print *tab, const char *format, int pos)
{
	// int		i;
	unsigned long long		j;
	int len;

	// i = 0;
	len = 0;
	j = va_arg(tab->args, long long);
	(void)format;
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	len = ft_len(j);
	if (len >= 10)
		len = 8;
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	len = ft_putnbr_base(j, "0123456789ABCDEF");
	ft_left_idupx(tab);
	if (len > tab->wdt)
		tab->tl = len;
	else
		tab->tl = tab->wdt;
	return (pos);
}
