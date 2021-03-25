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

char	*ft_itoabase(unsigned long long n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		l;

	if (base == 10)
		return (ft_itoa(n));
	l = 14;
	str = (char*)malloc(sizeof(*str) * (l + 1));
	i = 0;
	while (n > 0)
	{
		if (uppercase && base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	// if (str[i+1] != '\0')
	// 	free(&str[i+1]);
	return (str);
}

int	ft_output_hexa_intm(t_print *tab, const char *format, int pos)
{
	unsigned long long		j;
	int len;
	char *num;

	len = 0;
	j = va_arg(tab->args, long long);
	(void)format;
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	num = ft_itoabase(j, 16, 0);
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	// len = ft_putnbr_base();
	while(num[--len])
		tab->tl += write(1, &num[len], 1);
	ft_left_idupx(tab);
	// if (len > tab->wdt)
	// 	tab->tl = len;
	// else
	// 	tab->tl = tab->wdt;
	return (pos);
}

int	ft_output_hexa_intx(t_print *tab, const char *format, int pos)
{
	unsigned long long		j;
	int len;
	char *num;

	len = 0;
	j = va_arg(tab->args, long long);
	(void)format;
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	num = ft_itoabase(j, 16, 1);
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	// len = ft_putnbr_base();
	while(num[--len])
		tab->tl += write(1, &num[len], 1);
	ft_left_idupx(tab);
	// if (len > tab->wdt)
	// 	tab->tl = len;
	// else
	// 	tab->tl = tab->wdt;
	return (pos);
}
