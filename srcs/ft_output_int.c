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
<<<<<<< HEAD
	int		i;
	int		j;
	char	*num;
=======
	int i;
	int j;
	char *num;
	int len;
>>>>>>> main

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	num = ft_itoa(j);
<<<<<<< HEAD
	while (num[i])
=======
	len = ft_len(j);
	if (mytab->width > len && mytab->dash == 0)
		ft_fill_width_right(mytab,len);
	while(num[i])
>>>>>>> main
		write(1, &num[i++], 1);
	if (mytab->width > len && mytab->dash)
		ft_fill_width_left(mytab,len);
	else
		mytab->total_length += len;
	free(num);
<<<<<<< HEAD
	mytab->total_length += i;
=======
	//printf("%d\n", mytab->total_length);
>>>>>>> main
	return (pos);
}
