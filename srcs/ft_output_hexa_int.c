/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexa_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/22 11:26:39 by gregoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_hexa_len(unsigned long long n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}


char *ft_itoabase(char *str, unsigned long long n, int base, int c)
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

int	ft_output_hexa_int(t_print *tab, const char *format, int pos)
{
	unsigned long long		j;
	int len;
	char *num;

	j = va_arg(tab->args, long long);
	len = ft_hexa_len(j, 16);
	num = (char*)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	if (format[pos] == 'X')
		num = ft_itoabase(num, j, 16, 'A');
	else
		num = ft_itoabase(num, j, 16, 'a');
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	// while(num && len-- > 0)
	while(num && len-- > 0)
		tab->tl += write(1, &num[len], 1);
	ft_left_idupx(tab);
	free(num);
	return (pos);
}
