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
# define ULL		unsigned long long

# define	HH		1
# define	H		2
# define	L		4
# define	LL		8
# define	LD		16
# define	Z		32
# define	J		64
# define	T		128

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
	int		lf;
	int		size;
	int		asterisk;
	char	conversion;
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

typedef struct			s_float
{
	char	*left;
	char	sign;
	char	*zeros;
	char	*whole_part;
	char	*fract_part;
	char	*right;
}						t_float;

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
	wchar_t	wc;
	char	*right;
}						t_character;

typedef struct			s_fp_format
{
	unsigned long long		fraction : 64;
	unsigned int			exponent : 15;
	unsigned int			sign : 1;
}						t_fp_format;

union union_type
{
	long double					ld;
	//unsigned char			bit[10];
	t_fp_format				part;
};


typedef struct			s_f
{
	t_flags			*flags;
	t_string		*string;
	t_integer		*number;
	t_float			*f_number;
	t_character		*character;
}						t_f;


typedef enum
{
	UP,
	DOWN
}					t_reg;

int		ft_printf(const char *format, ...);
//
void	init_f(t_f *f);
int		get_flags(char *ptr, t_flags *flags, va_list arg_ptr);
int		ft_print_argument(va_list arg_ptr, t_f *f);
int		ft_print_int_unsigned(va_list arg_ptr, t_flags *flags);
//
void	print_and_free_int_struct(t_integer *number);
void	print_and_free_string_struct(t_string *string);
void	print_and_free_char_struct(t_f *f);
void	print_and_free_float_struct(t_float *number);

void	free_int_struct(t_integer *number);
void	free_string_srtuct(t_string *string);
void	free_char_srtuct(t_character *character);
void	free_float_struct(t_float *f_number);
//
int		get_number(va_list arg_ptr, t_f *f);
void	get_unsigned_number(va_list arg_ptr, t_f *f, int base);
void	get_hex_number(va_list arg_ptr, t_f *f);
void	get_oct_number(va_list arg_ptr, t_f *f);
void	get_bin_number(va_list arg_ptr, t_f *f);
//
int		di_case(va_list arg_ptr, t_f *f);
int		x_case(va_list arg_ptr, t_f *f);
int		o_case(va_list arg_ptr, t_f *f);
int		b_case(va_list arg_ptr, t_f *f);
int		u_case(va_list arg_ptr, t_f *f);
int		p_case(va_list arg_ptr, t_f *f);
int		f_case(va_list arg_ptr, t_f *f);

char	*n_char(char c, int n, int *len);
void	free_flags(t_flags *flags);
int		ft_print_string(va_list arg_ptr, t_f *f);
int		ft_print_char(va_list arg_ptr, t_f *f);
int		ft_print_adress(va_list arg_ptr, t_f *f);
char	*ft_itoa_base(int value, int base, int up);
char	*ft_itoa_base_long(long long value, int base, int up);
char	*ft_itoa_base_unsigned(unsigned long long value, int base, int up);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	print_and_free_int_struct(t_integer *number);
void	precision_case(t_f *f, int *len);
void	only_width_case(t_f *f, int *len);

void		multiply(ULL *rank, int exp);
//void	mult(ULL *m1, ULL *m2);
void	fill_array_by_zero(ULL *array);
void	ft_round(char *str_ptr, int sign);
void	rounding(char *str, int exp, t_f *f);
void	test();
int 	mult_test(ULL *m1, ULL *m2);
void	get(ULL *power, int exp);

void	di_only_width_case(t_f *f, int *len);
int		print_powers();
void		get_five_power(ULL *power, int exp);
void		mult(ULL *m1, ULL *m2);

void	put_dot(char *str, int exp, t_f *f);
int		test_prinf(const char *format);

#endif
