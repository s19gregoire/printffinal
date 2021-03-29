/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexa_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoire <gregoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:39:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/28 21:09:41 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_hexa_int(t_print *tab, int c)
{
	unsigned long long		j;
	int len;
	char *num;

	j = va_arg(tab->args, unsigned);
	if (!j)
	{
		ft_write_zero(tab);
		return ;
	}
	//printf("j %lld\n", j);
	len = ft_numlen_base(j, 16);
	//printf("len %d\n", len);
	num = (char*)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_update_tab(tab, len);
	ft_right_idupx(tab);
	while(num && len-- > 0)
		tab->tl += write(1, &num[len], 1);
	ft_left_idupx(tab);
	len = 0;
	free(num);
}
