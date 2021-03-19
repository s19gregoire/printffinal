/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/16 18:10:16 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_output_char(t_print *mytab, const char *format, int pos)
{
	char	a;

	a = va_arg(mytab->args, int);
	(void)format;
	if (mytab->width > 1 && mytab->dash == 0)
		ft_align_left(mytab, 1);
	write(1, &a, 1);
	if (mytab->width > 1 && mytab->dash == 1)
		ft_align_right(mytab, 1);
	else
		mytab->total_length += 1;
	return (pos);
}
