/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:07:35 by gneve             #+#    #+#             */
/*   Updated: 2021/04/01 09:47:23 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(char *str, unsigned long long n, int base, int c)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + c;
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (str);
}
