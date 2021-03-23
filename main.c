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
  static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

  ret = 0;
  ret2 = 0;
  ret = ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
  printf("|%i\n", ret);
  // - [OUTPUT] ft_printf("%p", NULL)
  ret2 = printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
  printf("|%i\n", ret2);
  return (0);
}