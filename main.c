/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:52:53 by mlazzare          #+#    #+#             */
/*   Updated: 2021/02/27 11:43:41 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int main(void)
{
  int ret;
  int ret2;

  ret = 0;
  ret2 = 0;
  ret = ft_printf("%07i", -54);
  printf("|%i\n", ret);
//
  // - [OUTPUT] ft_printf("%-10.5i", -216)
  // - [OUTPUT] ft_printf("%-8.5i", 0)
  // - [OUTPUT] ft_printf("%-8.3i", 8375)
  // - [OUTPUT] ft_printf("%-8.3i", -8473)
  // - [OUTPUT] ft_printf("%-3.7i", -2375)
  // - [OUTPUT] ft_printf("%08.5i", 34)
  // - [OUTPUT] ft_printf("%010.5i", -216)
  // - [OUTPUT] ft_printf("%08.5i", 0)
  // - [OUTPUT] ft_printf("%08.3i", 8375)
  // - [OUTPUT] ft_printf("%08.3i", -8473)
  // - [OUTPUT] ft_printf("%03.7i", -2375)
  // - [OUTPUT] ft_printf("%.0i", 0)
  // - [OUTPUT] ft_printf("%.i", 0)
  // - [OUTPUT] ft_printf("%5.0i", 0)
  // - [OUTPUT] ft_printf("%5.i", 0)
  // - [OUTPUT] ft_printf("%-5.0i", 0)
  // - [OUTPUT] ft_printf("%.3i", 0)
  // - [OUTPUT] ft_printf("%p", NULL)
  ret2 = printf("%07i", -54);
  printf("|%i\n", ret2);
  return (0);
}