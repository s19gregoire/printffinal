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

t_print *ft_initialise_tab(t_print *mytab)
{
	mytab->width = 0;
	mytab->precision = 0;
	mytab->zero = 0;
	mytab->point = 0;
	mytab->star = 0;
	mytab->is_neg = 0;
	mytab->left_aligned = 0;
	mytab->right_aligned = 0;
	mytab->special_chars = 0;
	mytab->total_length = 0;
	return (mytab);
}

void 	ft_update_char_counts(t_print *mytab, int pos)
{
	mytab->flag_chars += pos - mytab->position;
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
	t_print *mytab;
	int i;
	int r;

	r = 0;
	if (!(mytab = (t_print*)malloc(sizeof(t_print))))
		return (-1);
	ft_initialise_tab(mytab);
	i = -1;
	va_start(mytab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			// mytab->position = i;
			// mytab->flag_chars++;
			i++;
			i = ft_eval_input(mytab, format, i);
			//ft_update_char_counts(mytab, i);
			r += mytab->total_length;
		}
		else
			r += write(1, &format[i], 1);
  	}
	va_end(mytab->args);
	r = mytab->total_length; // + i - mytab->flag_chars;
	free(mytab);
	return (r);
}
