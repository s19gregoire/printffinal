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

void ft_update_total_length_string(t_print *mytab, int len)
{
	if (mytab->width >= mytab->precision)
		mytab->total_length += mytab->width;
	else
		mytab->total_length += len;
}

void ft_update_total_length(t_print *mytab, int len)
{
	if (mytab->width >= mytab->precision)
		mytab->total_length += mytab->width;
	else if (mytab->precision > mytab->width)
		mytab->total_length += mytab->precision;
	else
		mytab->total_length += len;
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
	num = ft_itoa(j);
	len = ft_strlen(num);
	ft_update_total_length(mytab, len);
	//if (mytab->width > len && mytab->width >= mytab->precision)
	ft_align_right(mytab,len);
	while(num[i])
		write(1, &num[i++], 1);
	//if (mytab->dash && mytab->width > len && mytab->width > mytab->precision)
	ft_align_left(mytab,len);
	free(num);
	//printf("%d\n", mytab->total_length);
	return (pos);
}
