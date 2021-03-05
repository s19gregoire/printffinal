/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/05 10:52:56 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		convert_to_hex(int nb)
{
	long int	i;
	char		*base;
	int			l;

	i = nb;
	base = "0123456789abcdef";
	l = 1;
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	if (i < 16)
	{
		ft_putchar(base[i % 16]);
		l++;
	}
	else
	{
		convert_to_hex(i / 16);
		ft_putchar(i % 16 + '0');
		l++;
	}
	return (l);
}

int		ft_output_pointer(t_print *mytab, const char *format, int pos)
{
	int i;
	int j;

	i = 2;
	j = va_arg(mytab->args, int);
	(void)format;
	write(1, "0x", 2);
	i += convert_to_hex(j);
	mytab->total_length += i;
	return (pos);
}
