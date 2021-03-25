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

char		*ft_unsigned_itoa(unsigned int nb)
{
	char	*a;
	int		l;

	l = ft_len(nb);
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


int ft_output_unsigned_int(t_print *tab, const char *format, int pos)
{
	int i;
	unsigned int j;
	char *num;
	int len;

	i = 0;
	j = va_arg(tab->args, int);
	(void)format;
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	num = ft_unsigned_itoa(j);
	len = ft_len(j);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while(num[i])
		tab->tl += write(1, &num[i++], 1);
	ft_left_idupx(tab);
	free(num);
	return (pos);
}
