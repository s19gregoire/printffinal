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

int ft_check_sign(t_print *mytab, int j)
{
	if (mytab->dash)
		 write(1, "-", 1);
	mytab->sign = 1;
	return (j * -1);
}

void ft_write_zero(t_print *mytab)
{
	mytab->is_zero = 1;
	if ((mytab->point && mytab->width) || (mytab->zero && mytab->width))
	{
		mytab->total_length = mytab->width;
		if (!mytab->precision)
		{
			if (mytab->zero)
			{
				while (mytab->width--)
					write(1, "0", 1);
			}
			else
			{
				while (mytab->width--)
					write(1, " ", 1);
			}
		}
		else
		{
			mytab->width -= mytab->precision;
			if (mytab->dash)
			{
				while (mytab->precision--)
					write(1, "0", 1);
			}
			while (mytab->width--)
				write(1, " ", 1);
			if (!mytab->dash)
			{
				while (mytab->precision--)
					write(1, "0", 1);
			}
		}
		return ;
	}
	if (mytab->point)// && mytab->width)
	{
		if (!mytab->width && mytab->precision)
		{
			mytab->total_length = mytab->precision;
			while (mytab->precision--)
				write(1, "0", 1);
		}
		else
		{
			mytab->total_length = mytab->width;
			while (mytab->width--)
				write(1, " ", 1);
		}
		return ;
	}
	ft_update_mytab(mytab, 1);
	while (!mytab->dash && --mytab->width > 0)
		write(1, " ", 1);
	write(1, "0", 1);
	while (mytab->dash && --mytab->width > 0)
	 	write(1, " ", 1);
}

int ft_output_int(t_print *mytab, const char *format, int pos)
{
	int i;
	int j;
	char *num;
	int len;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	if (!j)
	{
		ft_write_zero(mytab);
		return (pos);
	}
	if (j < 0)
		j = ft_check_sign(mytab, j);
	num = ft_itoa(j);
	len = ft_strlen(num);
	ft_update_mytab(mytab, len);
	ft_align_right(mytab);
	while(j && num[i])
		write(1, &num[i++], 1);
	ft_align_left(mytab);
	free(num);
	return (pos);
}
