/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/02 17:07:45 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_output_char(t_print *mytab, const char *format, int pos)
{
	char a;

	a = va_arg(mytab->args, int);
	(void)format;
	if (mytab->width > 0)
	{
		mytab->total_length += mytab->width;
		if (mytab->zero == 1)
		{
			while (mytab->width-- > 1)
				write(1, "0", 1);
			write(1, &a, 1);
		}
		else
		{
			while (mytab->width-- > 1)
				write(1, " ", 1);
			write(1, &a, 1);
		}
	}
	else
	{
		write(1, &a, 1);
		mytab->total_length += 1;
	}
	//printf("%d\n", mytab->total_length);
	return (pos);
}
