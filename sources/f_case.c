/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_array_by_zero(ULL *rank)
{
	int		i;

	i = 0;
	while (i < MAX_RANK)
	{
		rank[i] = 0;
		i++;
	}
}

void	get_fraction(ULL *rank, unsigned long long fraction)
{
	int		i;

	i = 0;
	while (fraction)
	{
		rank[i++] = fraction % 1000000000;
		fraction = fraction / 1000000000;
	}
	rank[i] = -1;
}

int		len_digit_str(ULL *rank)
{
	int		i;
	int		k;
	int		len;

	i = MAX_RANK - 1;
	len = 0;
	while (!rank[i] || rank[i] == (ULL)(-1))
		i--;
	k = 1;
	while (rank[i] / k)
	{
		len++;
		k *= 10;
	}
	len += i * 9;
	return (len);
}

char	*convert_to_str(ULL *rank, int exp)
{
	char	*str;
	char	*tmp_str;
	int		len;
	int		len_fract;
	int		i;
	int		k;

	len = len_digit_str(rank);
	len_fract = exp < 0 ? -exp : 0;
	//printf("len = %d\n", len);
	//printf("len_fract= %d\n", len_fract);
	str = (char *)malloc(sizeof(char) * (ft_max(len, len_fract) + 2));
	tmp_str = str;
	//str[len + 1] = 0;
	*str = '0';
	str++;
	k = 100000000;
	i = len / 9;

	if (exp < 0 && -exp - len > 0)
	{
		exp = -exp - len;
		while (exp)
		{
			*str = '0';
			exp--;
			str++;
		}
	}

	while (k && rank[i] / k == 0)
		k /= 10;
	if (!k)
		i--;
	while (i >= 0)
	{
		if (!k)
			k = 100000000;
		while (k)
		{
			len = rank[i];
			*str = rank[i] / k + '0';
			rank[i] %= k;
			str++;
			k /= 10;
		}
		i--;
	}
	*str = 0;
	return (tmp_str);
}

void	f_width_case(t_f *f, int *len)
{
	*len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
	{
		if (f->flags->zero)
			f->number->zeros = n_char('0', f->flags->width - *len, len);
		else
			f->number->left = n_char(' ', f->flags->width - *len, len);
	}
}

int		positive_exp(t_f *f)
{
	int		len;
	//int		tmp;

	if (f->number->digits[0] == '0')
		f->number->digits++;
	len = ft_strlen(f->number->digits);
	if (!f->number->sign && f->flags->space)
		f->number->sign = '+';
	di_only_width_case(f, &len);
	return (len);
}

int		f_case(va_list arg_ptr, t_f *f)
{
	ULL					rank[MAX_RANK];
	union union_type	number;
	int					exp;
	int					len = 0;
	char				*str;
	//int					i;

	fill_array_by_zero(rank);
	if (f->flags->lf)
		number.ld = va_arg(arg_ptr, long double);
	else
		number.ld = (long double)va_arg(arg_ptr, double);
	//
	f->number->sign = number.part.sign ? '-' : 0;
	if (!number.part.sign)
	{
		if (f->flags->space)
			f->number->sign = ' ';
		if (f->flags->plus)
			f->number->sign = '+';
	}
	get_fraction(rank, number.part.fraction);
	exp = number.part.exponent - 16383 - 63;
	//printf("exp = %d\n", exp);
	multiply(rank, exp);
	str = convert_to_str(rank, exp);
	//printf("%s\n", str);
	//
	rounding(str, exp, f);
	//printf("%s\n", str);
	if (*str == '0' && ft_strlen(str) == 1)
	{

	}
	
	put_dot(str, exp, f);
	//printf("%s\n", f->number->digits);

	len = ft_strlen(f->number->digits);
	f_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);

	return (len);
}

