/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/02 16:05:56 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	n_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_unsigned_itoa(unsigned int nb)
{
	char	*a;
	int		l;

	l = n_len(nb);
	if (!(a = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	a[l--] = '\0';
	if (nb == 0)
		a[l] = 0 + '0';
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}


int ft_output_unsigned_int(t_print *mytab, const char *format, int pos)
{
	int i;
	unsigned int j;
	char *num;
	int len;

	i = 0;
	j = va_arg(mytab->args, int);
	(void)format;
	num = ft_unsigned_itoa(j);
	len = ft_len(j);
	ft_update_mytab(mytab, len);
	// if (mytab->width > len && mytab->dash == 0)
		ft_align_right(mytab);
	while(num[i])
		write(1, &num[i++], 1);
	// if (mytab->width > len && mytab->dash)
		ft_align_left(mytab);
	// else
	// 	mytab->total_length += len;
	free(num);
	return (pos);
}
