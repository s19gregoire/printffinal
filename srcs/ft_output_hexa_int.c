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

// char	*ft_itoabase(int n, char *base)
// {
// 	int					c;
// 	unsigned int		tmp;
// 	char				*res;
// 	unsigned int		base_length;
//
// 	base_length = ft_strlen(base);
// 	c = (n < 0) ? 2 : 1;
// 	tmp = (n < 0) ? -n : n;
// 	while (tmp >= base_length && (tmp /= base_length))
// 		c++;
// 	// tmp = (n < 0) ? -n : n;
// 	if (!(res = (char*)malloc(sizeof(char) * (c + 1))))
// 		return (NULL);
// 	if (n < 0)
// 		res[0] = '-';
// 	res[c--] = '\0';
// 	while (tmp >= base_length)
// 	{
// 		res[c--] = base[tmp % base_length];
// 		tmp /= base_length;
// 	}
// 	res[--c] = base[tmp % base_length];
// 	return (res);
// }
//
// char		*ft_itoa(int n)
// {
// 	char	*a;
// 	int		l;
// 	long	long nb;
//
// 	nb = n;
// 	l = n_len(nb);
// 	if (!(a = (char *)malloc(sizeof(char) * (l + 1))))
// 		return (NULL);
// 	a[l--] = '\0';
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		a[0] = '-';
// 	}
// 	if (nb == 0)
// 	{
// 		a[l] = 0 + '0';
// 	}
// 	while (nb > 0)
// 	{
// 		a[l--] = nb % 10 + '0';
// 		nb /= 10;
// 	}
// 	return (a);
// }

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
		write(1, &num[len], 1);
	ft_left_idupx(tab);
	if (len > tab->wdt)
		tab->tl = len;
	else
		tab->tl = tab->wdt;
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
		write(1, &num[len], 1);
	ft_left_idupx(tab);
	if (len > tab->wdt)
		tab->tl = len;
	else
		tab->tl = tab->wdt;
	return (pos);
}
