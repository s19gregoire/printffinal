/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:52:53 by mlazzare          #+#    #+#             */
/*   Updated: 2021/03/25 17:57:24 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int main(void)
{
  int		a = 19;
	int		b = 14;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
  static unsigned int		mx_u = 235;
static char				mx_c = 'G';
static char			   *mx_s = "Hello, World!";
static int				mx_i = 42;
  int ret;
  int ret2;

  ret = 0;
  ret2 = 0;
  ret = ft_printf("%7.5s", "bombastic");
  //ret = ft_printf("  %u    %%    %p    %x    %s    %i  ",  mx_u, &mx_i, mx_u, mx_s, mx_i);
  printf("|%i\n", ret);
//   First line of code: {return test("%02.7X", 3267);}
//
// Test 471 (X_prec_width_fn_pos_ljzp_ignoreflag) : FAILED.
// First line of code: {return test("%0-2.7X", 3267);}
//
// Test 489 (new2019_negstar_1) : FAILED.
// First line of code: {return test("%*s", -32, "abc");}
//
// Test 490 (new2019_negstar_2) : FAILED.
// First line of code: {return test("%-*s", -32, "abc");}
// First line of code: {return test("%-*.*s", -7, -3, "yolo");}
// Test 495 (new2019_negstar_7) : FAILED.
// First line of code: {return test();}

  ret2 = printf("%7.5s", "bombastic");
  printf("|%i\n", ret2);
  return (0);
}
