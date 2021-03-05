/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/04 09:21:43 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_output_string(t_print *mytab, const char *format, int pos)
{
	char *s;
	int i;
	int l;

	(void)format;
	(void)pos;
	if (mytab->point == 1 && mytab->precision == 0)
		return (pos);
	i = -1;
	s = va_arg(mytab->args, char *);
	l = ft_strlen(s);
	if (l >= mytab->width)
		mytab->total_length += l;
	else
	{
		mytab->total_length += mytab->width;
		while (mytab->width-- > l)
		{
			if (mytab->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
	while (s[++i])
		write(1, &s[i], 1);
	return (pos);
}
