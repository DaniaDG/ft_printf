/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:00:26 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/23 10:00:27 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>


typedef struct			s_flags
{
	int		zero;
	int		minus;
	int		plus;
	int		width;
	int		dot;
	int		precision;
	int		space;
	int		h;
	int		hh;
	int		l;
	int		ll;
}						t_flags;

typedef struct			s_integer
{
	char	*left;
	char	sign;
	char	*zeros;
	char	*digits;
	char	*right;
}						t_integer;

typedef struct			s_srting
{
	char	*left;
	char	*str;
	char	*right;
}						t_string;

typedef struct			s_character
{
	char	*left;
	char	c;
	char	*right;
}						t_character;



int		ft_printf(const char *format, ...);
//int		ft_print_int(int arg, t_flags *flags);
int		ft_print_int(va_list arg_ptr, t_flags *flags);
int		ft_print_int_unsigned(va_list arg_ptr, t_flags *flags);
char	*n_char(char c, int n, int *len);
int		ft_intlen(int n);
void	free_flags(t_flags *flags);
int		ft_print_string(char *arg, t_flags *flags);
int		ft_print_char(char ch, t_flags *t_flags);
char	*ft_itoa_base(int value, int base);
char	*ft_itoa_base_long(long long value, int base);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
