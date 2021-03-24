/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 14:20:48 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_write_str_with_point(t_print *tab, int pos)
{
	ft_update_total_length_string(NULL, tab, 0);
	while (tab->wdt--)
		write(1, " ", 1);
	return (pos);
}

void ft_write_null(t_print *tab)
{
	char	*s;
	int		i;

	s = "(null)";
	i = 0;
	if (tab->pnt && tab->prc >= 0 && tab->prc < 6)
	{
		tab->tl = tab->wdt;
		while (tab->wdt--)
			write(1, " ", 1);
		return ;
	}
	while (!tab->dash && tab->wdt-- > 6)
		write(1, " ", 1);
	while(s[i])
		write(1, &s[i++], 1);
	while (tab->dash && tab->wdt-- > 6)
	 	write(1, " ", 1);
}

int ft_output_string(t_print *tab, const char *format, int pos)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	(void)format;
	len = 6;
	s = va_arg(tab->args, char *);
	if (s && tab->pnt == 1 && tab->prc == 0)
		return (pos = ft_write_str_with_point(tab, pos));
	len = ft_update_total_length_string(s, tab, len);
	if (s && !tab->dash && tab->wdt > len)
		ft_right_cs(tab, len);
	if (!s)
		ft_write_null(tab);
	else
	{
		if (tab->prc > 0)
			while (s[i] && tab->prc--)
				write(1, &s[i++], 1);
		else
			while (s[i])
				write(1, &s[i++], 1);
	}
	if (s && tab->dash && tab->wdt)
		ft_left_cs(tab, len);
	return (pos);
}
