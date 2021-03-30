/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_dash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:33:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/30 18:24:38 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_eval_zero(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	tab->zero = 1;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	tab->wdt = i;
	return (pos);
}

int ft_eval_precision(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	tab->pnt = 1;
	while (format[pos] == '0')
	{
		pos++;
		tab->zero = 0;
	}
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
		//tab->zero = 0;
	}
	tab->prc = i;
	if (format[pos] == '*')
	{
		pos = ft_eval_star(tab, format, pos);
	//	tab->zero = 0;
	}

	return (pos);
}

int ft_eval_dash(t_print *tab, const char *format, int pos)
{
	pos++;
	tab->dash = 1;
	tab->zero = 0;
	while (format[pos] == '-' || format[pos] == '0')
		pos++;
	pos = ft_eval_width(tab, format, pos);
	return (pos);
}

int ft_eval_star(t_print *tab, const char *format, int pos)
{
	pos++;
	tab->star = 1;
	if (!tab->pnt)
	{
		tab->wdt = va_arg(tab->args, int);
		if (tab->wdt < 0)
		{
			tab->wdt *= -1;
			tab->dash = 1;
			tab->zero = 0;
		}
	}
	else
	{
		tab->prc = va_arg(tab->args, int);
		if (tab->prc == 0)
			tab->zero = 0;
		if (tab->prc < 0)
		{
			tab->prc = 0;
			tab->pnt = 0;
		}
	//	else
	//		tab->zero = 0;
	}
	if (format[pos] == '.')
	{
		tab->pnt = 1;
		pos++;
	}
	if (ft_isdigit(format[pos]) || format[pos] == 0)
	{
		tab->prc = ft_atoi(&format[pos]);
		pos += ft_len(tab->prc);
		if (tab->prc == 0)
			tab->zero = 0;
	}
	if (format[pos] == '*')
	{
		tab->prc = va_arg(tab->args, int);
		if (tab->prc == 0)
			tab->zero = 0;
		if (tab->prc < 0)
		{
			tab->prc = 0;
			tab->pnt = 0;
		}
		//else
			//tab->zero = 0;
		pos++;
	}
	return (pos);
}

int ft_eval_width(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_len(i);
	}
	tab->wdt = i;
	if (format[pos] == '.')
		pos = ft_eval_precision(tab, format, pos);
	return (pos);
}
