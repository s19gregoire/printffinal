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

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void ft_write_nil(t_print *tab)
{
	char *s;
	int i;

	s = "(nil)";
	i = 0;
	if (tab->pnt && tab->prc < 5 && tab->prc > 0)
	{
		tab->tl = tab->wdt;
		while (tab->wdt--)
			write(1, " ", 1);
		return ;
	}
		while (!tab->dash && tab->wdt-- > 5)
			write(1, " ", 1);
		while(s[i])
			write(1, &s[i++], 1);
		while (tab->dash && tab->wdt-- > 5)
			write(1, " ", 1);
}

int ft_output_pointer(t_print *tab, const char *format, int pos)
{
	int i;
	unsigned long long j;

	i = 1;
	j = va_arg(tab->args, unsigned long long);
	(void)format;
	if (!j)
	{
		ft_write_nil(tab);
		return (pos);
	}
	ft_update_tab(tab, 14);
	ft_right_idupx(tab);
	write(1, "0x", 2);
	i += ft_putnbr_base_unsigned(j, "0123456789abcdef");
	ft_left_idupx(tab);
	return (pos);
}
