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

int ft_output_int(t_print *mytab, const char *format, int pos)
{
	int i;
	int j;
	char *num;
	int len;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	if ((j < 0 && mytab->precision >= mytab->width) || (j < 0 && !mytab->precision))
	{
		write(1, "-", 1);
		mytab->total_length += 1;
		mytab->width -= 1;
		j *= -1;
	}
	else if (j < 0)
	{
		mytab->sign = 1;
		//mytab->width -= 1;
		j *= -1;
	}
	num = ft_itoa(j);
	len = ft_strlen(num);
	ft_update_total_length(mytab, len);
	//if (mytab->width > len && mytab->width >= mytab->precision)
	ft_align_right(mytab, len);
	while(num[i])
		write(1, &num[i++], 1);
	//if (mytab->dash && mytab->width > len && mytab->width > mytab->precision)
	ft_align_left(mytab,len);
	free(num);
	//printf("%d\n", mytab->total_length);
	return (pos);
}
