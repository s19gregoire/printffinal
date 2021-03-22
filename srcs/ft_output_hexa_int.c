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

void	ft_putnbr_base(int n, char *base)
{
	int	tb;

	tb = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		ft_putchar(45);
	}
	if (n >= 9)
	{
		ft_putnbr_base(n / tb, base);
		ft_putchar(base[n % tb]);
	}
	if (n <= 9 && n >= 0)
		ft_putchar(base[n]);
}

int	ft_output_hexa_intm(t_print *mytab, const char *format, int pos)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	ft_putnbr_base(j, "0123456789abcdef");
	free(num);
	mytab->total_length += i;
	return (pos);
}

int	ft_output_hexa_intx(t_print *mytab, const char *format, int pos)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	ft_putnbr_base(j, "0123456789ABCDEF");
	free(num);
	mytab->total_length += i;
	return (pos);
}
