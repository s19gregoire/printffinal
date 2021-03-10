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

void ft_write_null()
{
	char *s;

	s = "(null)";
	while(*s)
		write(1, s++, 1);
}

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
	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (mytab->width > len && mytab->dash == 0)
		ft_fill_width_right(mytab, len);
	if (!s)
		ft_write_null();
	else
		while(s[i])
			write(1, &s[i++], 1);
	if (mytab->width > len && mytab->dash)
		ft_fill_width_left(mytab, len);
	else
		mytab->total_length += len;
	return (pos);
}
