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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	convert_to_hex(int nb)
{
	long int	i;
	long		len_base;
	char *base;
	int l;

	i = nb;
	len_base = 16;
	base = "0123456789abcdef";
	l = 1;
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	if (i < len_base)
	{
		ft_putchar(base[i % len_base]);
		l++;
	}
	else
	{
		l += convert_to_hex(i / len_base);
		ft_putchar(i % len_base + '0');
	}
	return (l);
}

int ft_output_pointer(t_print *mytab, const char *format, int pos)
{
	int i;
	int j;

	i = 1;
	j = va_arg(mytab->args, int);
	(void)format;
	write(1, "0x", 2);
	i += convert_to_hex(j);
	mytab->total_length += i;
	return (pos);
}
