/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/04 09:20:03 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_len(int num)
{
	int i;

	i = 0;
	if (num == 0)
		return (i);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i - 1);
}

int	ft_eval_width(t_print *mytab, const char *format, int pos)
{
	int i;

	i = 0;
	while (ft_isdigit(format[pos]))
		i = i * 10 + ft_atoi(&format[pos++]);
	mytab->width = i;
	pos += ft_len(i);
	return (pos);
}
