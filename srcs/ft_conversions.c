/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/19 14:36:18 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_putnbr_base(long long n, char *base)
{
	long long	base_len;
	int l;

	l = 1;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		l += ft_putchar(45);
	}
	if (n >= base_len)
	{
		l += ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	if (n < base_len)
	{
		ft_putchar(base[n]);
		l++;
	}
	return (l);
}


int	ft_putnbr_base_unsigned(long long n, char *base)
{
	long long base_len;
	int l;

	l = 1;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		l += ft_putnbr_base_unsigned(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	if (n < base_len)
	{
		ft_putchar(base[n]);
		l++;
	}
	return (l);
}
