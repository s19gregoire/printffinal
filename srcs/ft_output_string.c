/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/19 14:00:25 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_write_null(t_print *mytab)
{
	char	*s;
	int		i;

	s = "(null)";
	i = 0;
	if (s && mytab->point == 1 && mytab->precision == 0)
		return (i);
	if (mytab->width > 0 && mytab->point)
	{
		while (mytab->width-- > 0)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
		while (s[i])
			write(1, &s[i++], 1);
	return (i);
}

int	ft_output_string(t_print *mytab, const char *format, int pos)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	(void)format;
	s = va_arg(mytab->args, char *);
	if (s && mytab->point == 1 && mytab->precision == 0)
		return (pos);
	if (s)
		len = ft_strlen(s);
	ft_update_total_length_string(mytab, len);
	if (!mytab->dash && mytab->width > len)
		ft_right_justify(mytab, len);
	if (!s)
		len = ft_write_null(mytab);
	else
	{
		if (mytab->precision > 0)
			while (s[i] && mytab->precision--)
				write(1, &s[i++], 1);
		else
			while (s[i])
				write(1, &s[i++], 1);
	}
	if (mytab->dash && mytab->width)
		ft_left_justify(mytab, len);
	return (pos);
}
