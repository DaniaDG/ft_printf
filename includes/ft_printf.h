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
# include <math.h>
# include <stddef.h>
# include <wchar.h>
# include <limits.h>

# define MAX_RANK	10000

# define HH			1
# define H			2
# define L			4
# define LL			8
# define LD			16
# define Z			32
# define J			64
# define T			128

typedef struct				s_flags
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
	int		lf;
	int		size;
	int		asterisk;
	char	conversion;
}							t_flags;

typedef struct				s_integer
{
	char	*left;
	char	sign;
	char	*ox;
	char	*zeros;
	char	*digits;
	char	*right;
}							t_integer;

typedef struct				s_srting
{
	char	*left;
	char	*str;
	char	*right;
}							t_string;

typedef struct				s_character
{
	char	*left;
	char	c;
	wchar_t	wc;
	char	*right;
}							t_character;

typedef struct				s_ld_part
{
	unsigned long long		fraction : 64;
	unsigned int			exponent : 15;
	unsigned int			sign : 1;
}							t_ld_part;

typedef union				u_ext_format
{
	long double				ld;
	t_ld_part				part;
}							t_ext_format;

typedef struct				s_f
{
	int						res;
	t_flags					*flags;
	t_string				*string;
	t_integer				*number;
	t_character				*character;
}							t_f;

int							ft_printf(const char *format, ...);
void						init_f(t_f *f);
int							get_flags(char *ptr, t_flags *flags,
												va_list arg_ptr);
int							ft_print_argument(va_list arg_ptr, t_f *f);
void						print_and_free_int_struct(t_integer *number);
void						print_and_free_string_struct(t_string *string);
void						print_and_free_char_struct(t_f *f, int *len);
void						free_int_struct(t_integer *number);
void						free_string_srtuct(t_string *string);
void						free_char_srtuct(t_character *character);
void						free_all(t_f *f);
void						free_flags(t_flags *flags);
int							get_number(va_list arg_ptr, t_f *f);
void						get_unsigned_number(va_list arg_ptr, t_f *f,
															int base);
long double					get_ld_number(va_list arg_ptr, t_f *f);
void						get_adress(va_list arg_ptr, t_f *f);
int							di_case(va_list arg_ptr, t_f *f);
int							x_case(va_list arg_ptr, t_f *f);
int							o_case(va_list arg_ptr, t_f *f);
int							b_case(va_list arg_ptr, t_f *f);
int							u_case(va_list arg_ptr, t_f *f);
int							p_case(va_list arg_ptr, t_f *f);
int							f_case(va_list arg_ptr, t_f *f);
int							s_case(va_list arg_ptr, t_f *f);
int							c_case(va_list arg_ptr, t_f *f);
char						*n_char(char c, int n, int *len);
char						*ft_itoa_base(int value, int base, int up);
char						*ft_itoa_base_long(long long value, int base,
																int up);
char						*ft_itoa_base_unsigned(unsigned long long value,
													int base, int up);
int							ft_max(int a, int b);
int							ft_min(int a, int b);
void						fill_array_by_zero(unsigned long long *array);
int							check_special_numbers(t_ext_format number, t_f *f);
void						get_fraction(unsigned long long *rank,
											unsigned long long fraction);
void						multiply(unsigned long long *rank, int exp);
char						*convert_to_str(unsigned long long *rank, int exp);
void						rounding(char *str, int exp, t_f *f);
void						put_dot(char *str, int exp, t_f *f);

#endif
