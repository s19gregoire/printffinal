/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:16:38 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/28 21:53:43 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_numlen_base(long long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		i += 1;
	else if (n < 0)
	{
		//i += 1;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

