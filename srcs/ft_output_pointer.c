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

void ft_write_nil(t_print *mytab)
{
	char *s;
	int i;

	s = "(nil)";
	i = 0;
	if (mytab->point && mytab->precision < 5 && mytab->precision >= 0)
	{
		mytab->total_length = mytab->width;
		while (mytab->width--)
			write(1, " ", 1);
		return ;
	}
		while (!mytab->dash && mytab->width-- > 5)
			write(1, " ", 1);
		while(s[i])
			write(1, &s[i++], 1);
		while (mytab->dash && mytab->width-- > 5)
			write(1, " ", 1);
}

int ft_output_pointer(t_print *mytab, const char *format, int pos)
{
	int i;
	unsigned long long j;

	i = 1;
	j = va_arg(mytab->args, unsigned long long);
	(void)format;
	if (!j)
	{
		ft_write_nil(mytab);
		return (pos);
	}
	ft_update_mytab(mytab, 14);
	ft_align_right(mytab);
	write(1, "0x", 2);
	i += ft_putnbr_base_unsigned(j, "0123456789abcdef");
	ft_align_left(mytab);
	return (pos);
}
