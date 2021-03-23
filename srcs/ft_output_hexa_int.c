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

int	ft_putnbr_base(long long n, char *base)
{
	long long	tb;
	int l;

	l = 0;
	tb = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		l += ft_putchar(45);
	}
	if (n >= 9)
	{
		l++;
		ft_putnbr_base(n / tb, base);
		ft_putchar(base[n % tb]);
	}
	if (n <= 9 && n >= 0)
		l += ft_putchar(base[n]);
	return (l);
}


int	ft_putnbr_base_unsigned(long long n, char *base)
{
	long long base_len;
	int l;

	l = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		l++;
		ft_putnbr_base_unsigned(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
	if (n < base_len)
		l += ft_putchar(base[n]);
	return (l);
}

int	ft_output_hexa_intm(t_print *mytab, const char *format, int pos)
{
	int		i;
	unsigned int		j;

	i = 0;
	j = va_arg(mytab->args, long long);
	(void)format;
	ft_putnbr_base(j, "0123456789abcdef");
	mytab->total_length += i;
	return (pos);
}

int	ft_output_hexa_intx(t_print *mytab, const char *format, int pos)
{
	int		i;
	unsigned long long		j;

	i = 0;
	j = va_arg(mytab->args, long long);
	(void)format;
	i += ft_putnbr_base(j, "0123456789ABCDEF");
	mytab->total_length += i;
	return (pos);
}
