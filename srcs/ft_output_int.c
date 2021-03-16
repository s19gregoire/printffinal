/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/12 13:55:39 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_check_sign(t_print *mytab, int j)
{
	if (mytab->precision >= mytab->width || !mytab->precision)
	{
		write(1, "-", 1);
		mytab->total_length += 1;
		mytab->width -= 1;
	}
	else if (j < 0)
		mytab->sign = 1;
	return (j * -1);
}

int ft_output_int(t_print *mytab, const char *format, int pos)
{
	int		i;
	int		j;
	char	*num;
	int		len;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	if (j < 0)
		j = ft_check_sign(mytab, j);
	num = ft_itoa(j);
	len = ft_strlen(num);
	ft_update_mytab(mytab, len);
	//if (mytab->width > len && mytab->width >= mytab->precision)
	ft_align_right(mytab, len);
	while(num[i])
		write(1, &num[i++], 1);
	//if (mytab->dash && mytab->width > len && mytab->width > mytab->precision)
	ft_align_left(mytab,len);
	free(num);
	return (pos);
}
