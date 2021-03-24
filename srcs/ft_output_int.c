/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/02 16:05:56 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_check_sign(t_print *tab, int j)
{
	if (tab->dash)
		 write(1, "-", 1);
	tab->sign = 1;
	return (j * -1);
}

void ft_write_zero(t_print *tab)
{
	tab->is_zero = 1;
	if (tab->wdt && (tab->pnt || tab->zero))
	{
		tab->tl = tab->wdt;
		if (!tab->prc)
		{
				while (tab->zero && tab->wdt-- > 0)
					write(1, "0", 1);
				while (!tab->zero && tab->wdt-- > 0)
					write(1, " ", 1);
		}
		else
		{
			tab->wdt -= tab->prc;
			while (tab->dash && tab->prc-- > 0)
				write(1, "0", 1);
			while (tab->wdt-- > 0)
				write(1, " ", 1);
			while (!tab->dash && tab->prc-- > 0)
				write(1, "0", 1);
		}
		return ;
	}
	if (tab->pnt)
	{
		if (tab->prc < 0)
		{
			tab->tl = 1;
			write(1, "0", 1);
		}
		if (!tab->wdt && tab->prc > 0)
		{
			tab->tl = tab->prc;
			while (tab->prc-- > 0)
				write(1, "0", 1);
		}
		else
		{
			tab->tl = tab->wdt;
			while (tab->wdt-- > 0)
				write(1, " ", 1);
		}
		return ;
	}
	ft_update_tab(tab, 1);
	while (!tab->dash && --tab->wdt > 0)
		write(1, " ", 1);
	write(1, "0", 1);
	while (tab->dash && --tab->wdt > 0)
	 	write(1, " ", 1);
}

int ft_output_int(t_print *tab, const char *format, int pos)
{
	int i;
	int j;
	char *num;
	int len;

	i = 0;
	j = va_arg(tab->args, int);
	(void)format;
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	if (j < 0)
		j = ft_check_sign(tab, j);
	num = ft_itoa(j);
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while(j && num[i])
		write(1, &num[i++], 1);
	ft_left_idupx(tab);
	free(num);
	return (pos);
}
