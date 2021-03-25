/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:07:35 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/08 12:44:10 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	int					c;
	unsigned int		tmp;
	char				*res;
	unsigned int		base_length;

	base_length = ft_strlen(base);
	c = (n < 0) ? 1 : 0;
	tmp = (n < 0) ? -n : n;
	// while (tmp >= base_length && (tmp /= base_length))
	// 	c++;
	// tmp = (n < 0) ? -n : n;
	if (!(res = (char*)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[c--] = '\0';
	while (tmp >= base_length)
	{
		res[c--] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--c] = base[tmp % base_length];
	return (res);
}