/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:45:09 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/25 18:00:22 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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