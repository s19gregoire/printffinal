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
	ft_update_mytab(mytab, 1);
	if (mytab->width && !mytab->dash)
		ft_right_justify(mytab, 0); // len should be removed from the function
	write(1, &a, 1);
	if (mytab->width && mytab->dash)
		ft_left_justify(mytab, 0);
	return (pos);
}
