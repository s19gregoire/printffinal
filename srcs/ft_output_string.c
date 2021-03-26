/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/26 11:53:23 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_write_point(t_print *tab)
{
	ft_update_tab_string(NULL, tab, 0);
	while (tab->wdt--)
		tab->tl += write(1, " ", 1);
}

void ft_write_null(t_print *tab, char *s)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(s);
	if (tab->pnt && tab->prc >= 0 && tab->prc < l)
	{
		while (tab->wdt--)
			tab->tl += write(1, " ", 1);
		return ;
	}
	while (!tab->dash && tab->wdt-- > l)
		tab->tl += write(1, " ", 1);
	while(s[i])
		tab->tl += write(1, &s[i++], 1);
	while (tab->dash && tab->wdt-- > l)
	 	tab->tl += write(1, " ", 1);
}

void ft_output_string(t_print *tab)
{
	char *s;
	int i;
	int len;

	i = 0;

	len = 6;
	s = va_arg(tab->args, char *);
	if (s && tab->pnt == 1 && tab->prc == 0)
		return (ft_write_point(tab));
	len = ft_update_tab_string(s, tab, len);
	if (s && !tab->dash && tab->wdt > len)
		ft_right_cs(tab, len);
	if (!s)
		ft_write_null(tab, "(null)");
	else
	{
		if (tab->prc > 0)
			while (s[i] && tab->prc--)
				tab->tl += write(1, &s[i++], 1);
		else
			while (s[i])
				tab->tl += write(1, &s[i++], 1);
	}
	if (s && tab->dash && tab->wdt)
		ft_left_cs(tab, len);
}
