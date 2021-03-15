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
  char c;
  int ret;
  int ret2;

  c = 'A';
  ret = ft_printf("%.03s", NULL);
  printf("|%i\n", ret);
  // ret = ft_printf("%p", NULL);
//   - [OUTPUT] ft_printf()
// - [OUTPUT] ft_printf("%p", NULL)
  ret2 = printf("%.03s", NULL);
  printf("|%i\n", ret2);
  return (0);
}
