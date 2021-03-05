/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_dash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/04 09:19:42 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_eval_dash(t_print *mytab, const char *format, int pos)
{
	pos++;
	(void)mytab;
	(void)format;
	mytab->dash = 1;
	// if (ft_isdigit(format[pos]))
	// {
	// 	while (ft_isdigit(format[pos]))
	// 		i = i * 10 + ft_atoi(&format[pos++]);
	// 	mytab->precision = i;
	// 	//pos += ft_len(i);
	// }
	// else
	// 	mytab->precision = 0;
	return (pos);
}
