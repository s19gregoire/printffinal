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

int ft_write_str_with_point(t_print *mytab, int pos)
{
	ft_update_total_length_string(NULL, mytab, 0);
	while (mytab->width--)
	{
		write(1, " ", 1);
	}
	return (pos);
}

void ft_write_null(t_print *mytab)
{
	char *s;
	int i;

	s = "(null)";
	i = 0;
	if (!mytab->width && mytab->point && !mytab->precision)
	{
		mytab->total_length = 0;
		return ;
	}
	// if (mytab->point)
	// {
	// 	while (mytab->width--)
	// 		write(1, " ", 1);
	// 	return ;
	// }
	// if (!mytab->dash && mytab->point && mytab->width && mytab->width < 6 && mytab->precision < 6) // > 0 )
	// {
	// 	while (mytab->width-- > 0)
	// 	{
	// 		write(1, " ", 1);
	// 		i++;
	// 	}
	// }
	// else
	// {
		while (!mytab->dash && mytab->width-- > 6)
			write(1, " ", 1);
		while(s[i]) // && !mytab->point)
			write(1, &s[i++], 1);
		while (mytab->dash && mytab->width-- > 6)
		 	write(1, " ", 1);
	// }
}

int ft_output_string(t_print *mytab, const char *format, int pos)
{
	char *s;
	int i;
	int len;

	i = 0;
	(void)format;
	len = 6;
	s = va_arg(mytab->args, char *);
	if (s && mytab->point == 1 && mytab->precision == 0)
		return (pos = ft_write_str_with_point(mytab, pos));
	len = ft_update_total_length_string(s, mytab, len);
	if (s && !mytab->dash && mytab->width > len)
		ft_right_justify(mytab, len);
	if (!s)
		ft_write_null(mytab);
	else
	{
		if (mytab->precision > 0)
		{
			while(s[i] && mytab->precision--)
				write(1, &s[i++], 1);
		}
		else
		{
			while(s[i])
				write(1, &s[i++], 1);
		}
	}
	if (s && mytab->dash && mytab->width)
		ft_left_justify(mytab, len);
	return (pos);
}
