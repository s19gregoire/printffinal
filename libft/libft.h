/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:46:12 by gneve             #+#    #+#             */
/*   Updated: 2021/04/01 09:53:04 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define MAX_LONG	9223372036854775807
# define MIN_LONG	-9223372036854775808
# define MAX_INT	2147483648
# define MIN_INT	-2147483647

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t			ft_strlen(const char *s);
int				ft_numlen_base(unsigned long n, int base);
int				ft_putnbr_base(unsigned long long n, char *base);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_putchar(char c);
int				ft_atoi(const char *nptr);
void			ft_putnbr(int nbr);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_itoa_base(char *str, unsigned long long n, int base, int c);

#	endif
