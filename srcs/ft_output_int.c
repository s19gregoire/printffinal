/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/29 11:40:42 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_check_sign(t_print *tab, int j)
{
	if (j > MIN_INT)
		tab->sign = 1;
	return (j * -1);
}

void ft_write_zero(t_print *tab)
{
	tab->is_zero = 1;
	if (tab->wdt || tab->pnt)
	{
		ft_right_zero(tab);
		return ;
	}
	ft_update_tab(tab, 1);
	while (!tab->dash && --tab->wdt > 0)
		tab->tl += write(1, " ", 1);
	tab->tl += write(1, "0", 1);
	while (tab->dash && --tab->wdt > 0)
	 	tab->tl += write(1, " ", 1);
}

void ft_output_int(t_print *tab)
{
	int		i;
	int		j;
	char	*num;
	int		len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	if (j < 0)
		j = ft_check_sign(tab, j);
	num = ft_itoa(j);
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while(j && num[i])
		tab->tl += write(1, &num[i++], 1);
	ft_left_idupx(tab);
	len = 0;
	free(num);
}
