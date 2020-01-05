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
	int		sharp;
	int		percent;
	int		h;
	int		hh;
	int		l;
	int		ll;
	char	 conversion;
}						t_flags;

typedef struct			s_integer
{
	char	*left;
	char	sign;
	char	*ox;
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

typedef struct			s_size_number
{
	char					short_short_arg;
	short					short_arg;
	int						int_arg;
	long					long_arg;
	long long				long_long_arg;
	unsigned char			u_short_short_arg;
	unsigned short			u_short_arg;
	unsigned int			u_int_arg;
	unsigned long			u_long_arg;
	unsigned long long		u_long_long_arg;
}						t_size_number;

typedef struct			s_f
{
	t_flags			*flags;
	t_string		*string;
	t_integer		*number;
	t_character		*character;
}						t_f;

typedef enum
{
	UP,
	DOWN
}					t_reg;

int		ft_printf(const char *format, ...);
//
int		ft_print_int(va_list arg_ptr, t_f *f);
int		ft_print_int_unsigned(va_list arg_ptr, t_flags *flags);
char	*n_char(char c, int n, int *len);
int		ft_intlen(int n);
void	free_flags(t_flags *flags);
int		ft_print_string(va_list arg_ptr, t_f *f);
int		ft_print_char(va_list arg_ptr, t_f *f);
char	*ft_itoa_base(int value, int base, int up);
char	*ft_itoa_base_long(long long value, int base, int up);
char	*ft_itoa_base_unsigned(unsigned long long value, int base, int up);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
