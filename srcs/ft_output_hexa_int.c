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

char	*ft_itoabase(unsigned long long n, int base, int uppercase)
{
	char	*str;
	int  num;
	// int		i;
	int		l;

	// i = 0;
	// num = n;
	l = 8;
	if (base == 10)
		return (ft_itoa(n));
	while (num > 0)
	{
		l++;
		num = num / base;
	}
	str = (char*)malloc(sizeof(char) * (l + 1));
	str[l + 1] = '\0';
	if (!str)
		return (NULL);
	while (n > 0)
	{
		if (uppercase && base > 10 && (n % base >= 10))
			str[l--] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[l--] = (n % base) - 10 + 'a';
		else
			str[l--] = (n % base) + '0';
		n /= base;
	}

	// cpy = str;
	// free(str);
	return (str);
}

int	ft_output_hexa_int(t_print *tab, const char *format, int pos)
{
	unsigned long long		j;
	int len;
	char *num;
	int uppercase;

	len = 0;
	uppercase = 1;
	j = va_arg(tab->args, long long);
	if (!j)
	{
		ft_write_zero(tab);
		return (pos);
	}
	if (format[pos] == 'X')
		num = ft_itoabase(j, 16, uppercase);
	else
		num = ft_itoabase(j, 16, 0);
	len = ft_strlen(num);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	len = -1;
	while(num[++len])
		tab->tl += write(1, &num[len], 1);
	ft_left_idupx(tab);
	free(num);
	return (pos);
}
