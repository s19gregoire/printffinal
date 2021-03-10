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

int ft_write_null(t_print *mytab)
{
	char *s;
	int i;

	s = "(null)";
	i = 0;
	if (mytab->width > 0 && mytab->point)
	{
		while (mytab->width-- > 0)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
		while(s[i])
			write(1, &s[i++], 1);
	return (i);
}

int ft_output_string(t_print *mytab, const char *format, int pos)
{
	char *s;
	int i;
	int len;

	i = 0;
	(void)format;
	s = va_arg(mytab->args, char *);
	if (s && mytab->point == 1 && mytab->precision == 0)
		return (pos);
	if (s)
		len = ft_strlen(s);
	if (mytab->width > len && mytab->dash == 0)
		ft_fill_width_right(mytab, len);
	if (!s)
		len = ft_write_null(mytab);
	else
		while(s[i])
			write(1, &s[i++], 1);
	if (mytab->width > len && mytab->dash)
		ft_fill_width_left(mytab, len);
	else
		mytab->total_length += len;
	return (pos);
}
