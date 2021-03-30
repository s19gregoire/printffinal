/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/30 18:22:25 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int ft_update_tab_string(char *s, t_print *tab, int len)
{
	if (s)
		len = ft_strlen(s);
	if (tab->prc > 0 && len > tab->prc)
		len = tab->prc;
	return (len);
}

void ft_update_tab(t_print *tab, int len)
{
	if (tab->sign)
	{
		if (tab->wdt)
			tab->wdt -= 1;

	}
	if (tab->prc > 0)
		tab->zero = 0;
	if (tab->wdt && tab->wdt >= tab->prc)
	{
		if (tab->prc > len)
		{
			tab->prc -= len;
			//tab->zero = 0;
		}
	  else
	  {
			tab->prc = 0;
			//tab->zero = 0;
	}
		if (!tab->is_zero)
				tab->wdt = tab->wdt - tab->prc - len;
	}
	else if (tab->prc > tab->wdt)
	{
		tab->wdt = 0;
		tab->prc -= len;
	}
}
