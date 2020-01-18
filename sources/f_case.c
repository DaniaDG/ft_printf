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

void	fill_array_by_zero(long *rank, long *power)
{
	int		i;

	i = 0;
	while (i < 50)
	{
		rank[i] = 0;
		power[i] = 0;
		i++;
	}
}

void	get_fraction(long *rank, unsigned long long fraction)
{
	int		i;

	i = 1;
	while (fraction)
	{
		rank[i++] = fraction % 10000;
		fraction = fraction / 10000;
	}
}

void	get(long *power, int exp)
{
	int		i;

	power[1] = 1;
	if (exp > 0)
	{
		while (exp)
		{
			i = 1;
			while (i < 50)
			{
				power[i] *= 2;
				power[i] += power[i - 1] / 10000;
				power[i - 1] = power[i - 1] % 10000;
				i++;
			}
			exp--;
		}
	}
	if (exp < 0)
	{
		exp *= -1;
		while (exp)
		{
			i = 1;
			while (i < 50)
			{
				power[i] *= 5;
				power[i] += power[i - 1] / 10000;
				power[i - 1] = power[i - 1] % 10000;
				i++;
			}
			exp--;
		}
	}
}

int		len_digit_str(long *rank)
{
	int		i;
	int		k;
	int		len;

	i = 49;
	len = 0;
	while (!rank[i])
		i--;
	k = 1;
	while (rank[i] / k)
	{
		len++;
		k *= 10;
	}
	len += i * 4;
	return (len);
}

char	*convert_to_str(long *rank)
{
	char	*str;
	char	*tmp_str;
	int		len;
	int		i;
	int		k;

	len = len_digit_str(rank);
	str = (char *)malloc(sizeof(char) * (len + 2));
	tmp_str = str;
	str[len + 1] = 0;
	*str++ = '0';
	k = 1000;
	i = len / 4;
	while (rank[i] / k == 0)
		k /= 10;
	if (!k)
		i--;
	while (i > 0)
	{
		if (!k)
			k = 1000;
		while (k)
		{
			*str = rank[i] / k + '0';
			rank[i] %= k;
			str++;
			k /= 10;
		}
		i--;
	}
	return (tmp_str);
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
	long				rank[50];
	long				power[50];
	long double			ld;
	union union_type	number;
	int					exp;
	int					len = 0;
	char				*str;
	int					i;

	fill_array_by_zero(rank, power);
	if (f->flags->lf)
		ld = va_arg(arg_ptr, long double);
	else
		ld = (long double)va_arg(arg_ptr, double);
	number.ld = ld;
	f->number->sign = number.part.sign ? '-' : 0;
	get_fraction(rank, number.part.fraction);
	exp = number.part.exponent - 16383 - 63;
	get(power, exp);
	mult(rank, power);
	str = convert_to_str(rank);
	printf("%s\n", str);
	if (exp < 0)
	{
		i = ft_strlen(str) + exp;
		len = ft_strlen(str) + exp + f->flags->precision;
		rounding(str + len);
		len = ft_max(f->flags->precision, -exp) + 2;
		f->f_number->fract_part = (char*)malloc(sizeof(char) * len);
		f->f_number->fract_part[0] = '.';
		f->f_number->fract_part[len] = '\0';
		f->f_number->fract_part++;
		f->f_number->fract_part = ft_strcpy(f->f_number->fract_part, &str[i]);
		i = ft_strlen(str) - ft_strlen(f->f_number->fract_part);
		str[i] = 0;
		f->f_number->fract_part--;
		if (*str == '0')
			str++;
		f->f_number->whole_part = ft_strdup(str);
	}
	printf("%s\n", str);
	printf("%s%s\n", f->f_number->whole_part, f->f_number->fract_part);
	return (0);
}
