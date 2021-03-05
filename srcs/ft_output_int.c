/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/04 09:38:52 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_output_int(t_print *mytab, const char *format, int pos)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	num = ft_itoa(j);
	while (num[i])
		write(1, &num[i++], 1);
	free(num);
	mytab->total_length += i;
	return (pos);
}
