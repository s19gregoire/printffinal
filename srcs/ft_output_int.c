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
	num = ft_itoa(j);
	len = ft_strlen(num);
	if (mytab->width > mytab->precision && mytab->width > len && mytab->dash == 0)
		ft_fill_width_right(mytab,len);
	while(num[i])
		write(1, &num[i++], 1);
	if (mytab->width > mytab->precision && mytab->width > len && mytab->dash)
		ft_fill_width_left(mytab,len);
	else
		mytab->total_length += len;
	free(num);
	//printf("%d\n", mytab->total_length);
	return (pos);
}
