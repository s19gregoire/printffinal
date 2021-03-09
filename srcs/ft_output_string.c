/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/02/27 11:42:59 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_output_string(t_print *mytab, const char *format, int pos)
{
	char *s;
	int i;
	int len;

	(void)format;
	(void)pos;
	if (mytab->point == 1 && mytab->precision == 0)
		return (pos);
	i = 0;
	s = va_arg(mytab->args, char *);
	len = ft_strlen(s);
	if (mytab->width > 0 && mytab->width > len && mytab->dash == 0)
		ft_fill_width(mytab, len);
	while(s[i])
		write(1, &s[i++], 1);
	if (mytab->dash)
		ft_fill_width(mytab, len);
	else
		mytab->total_length += len;
	// if (l >= mytab->width)
	// 	mytab->total_length += l;
	// else
	// {
	// 	mytab->total_length += mytab->width;
	// 	while (mytab->width-- > l)
	// 	{
	// 		if (mytab->zero == 1)
	// 			write(1, "0", 1);
	// 		else
	// 			write(1, " ", 1);
	// 	}
	// }
	// while(s[++i])
	// 	write(1, &s[i], 1);
	return (pos);
}
