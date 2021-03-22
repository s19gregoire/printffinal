/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 08:05:45 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 14:01:49 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *little, size_t len)
{
	size_t				i;
	size_t				j;
	char				*ptr;

	ptr = (char *)b;
	if (!little[0])
		return (ptr);
	if (!len)
		return (NULL);
	i = 0;
	while (ptr[i] && i < len)
	{
		j = 0;
		while (ptr[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
