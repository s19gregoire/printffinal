/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:02:19 by mlazzare          #+#    #+#             */
/*   Updated: 2021/02/27 11:36:56 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print *ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->star = 0;
	tab->is_neg = 0;
	tab->special_chars = 0;
	tab->tl = 0;
	return (tab);
}

void 	ft_update_char_counts(t_print *tab, int pos)
{
	tab->flag_chars += pos - tab->position;
}

int is_a_flag(char c)
{
	char *flags;

	flags = "csiduxXp";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

int ft_percentage_check(const char *format, int pos)
{
	if (ft_isalpha(format[pos]) && (is_a_flag(format[pos])))
			return (0);
	return (1);
}

int ft_printf(const char *format, ...)
{
	t_print *tab;
	int i;
	int r;

	r = 0;
	if (!(tab = (t_print*)malloc(sizeof(t_print))))
		return (-1);
	ft_initialise_tab(tab);
	i = -1;
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			// tab->position = i;
			// tab->flag_chars++;
			i++;
			i = ft_eval_input(tab, format, i);
			//ft_update_char_counts(tab, i);
			r += tab->tl;
		}
		else
			r += write(1, &format[i], 1);
  	}
	va_end(tab->args);
	free(tab);
	return (r);
}
