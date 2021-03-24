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

int	ft_output_hexa_intm(t_print *mytab, const char *format, int pos)
{
	// int		i;
	unsigned long long		j;
	int len;

	// i = 0;
	len = 0;
	j = va_arg(mytab->args, long long);
	(void)format;
	if (!j)
	{
		ft_write_zero(mytab);
		return (pos);
	}
	len = ft_len(j);
	if (len >= 10)
		len = 8;
	ft_update_mytab(mytab, len);
	ft_align_right(mytab);
	len = ft_putnbr_base(j, "0123456789abcdef");
	ft_align_left(mytab);
	if (len > mytab->width)
		mytab->total_length = len;
	else
		mytab->total_length = mytab->width;
	return (pos);
}

int	ft_output_hexa_intx(t_print *mytab, const char *format, int pos)
{
	// int		i;
	unsigned long long		j;
	int len;

	// i = 0;
	len = 0;
	j = va_arg(mytab->args, long long);
	(void)format;
	if (!j)
	{
		ft_write_zero(mytab);
		return (pos);
	}
	len = ft_len(j);
	if (len >= 10)
		len = 8;
	ft_update_mytab(mytab, len);
	ft_align_right(mytab);
	len = ft_putnbr_base(j, "0123456789ABCDEF");
	ft_align_left(mytab);
	if (len > mytab->width)
		mytab->total_length = len;
	else
		mytab->total_length = mytab->width;
	return (pos);
}
