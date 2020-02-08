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

void	get_fraction(ULL *rank, ULL fraction)
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
	if (!(str = (char *)malloc(sizeof(char) * (ft_max(len, len_fract) + 2))))
		return (NULL);
	tmp_str = str;
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

static int		f_width_case(t_f *f)
{
	int		len;

	len = ft_strlen(f->number->digits);
	len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - len, &len);
	else
	{
		if (f->flags->zero)
			f->number->zeros = n_char('0', f->flags->width - len, &len);
		else
			f->number->left = n_char(' ', f->flags->width - len, &len);
	}
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}

static void		get_sign(unsigned char sign, t_f *f)
{
	f->number->sign = sign ? '-' : 0;
	if (!sign)
	{
		if (f->flags->space)
			f->number->sign = ' ';
		if (f->flags->plus)
			f->number->sign = '+';
	}
}

int		check_special_numbers(t_ext_format number, t_f *f)
{
	char	*str;
	int		bla;

	str = NULL;
	bla = 0;
	if (number.ld == 0)
	{
		if (f->flags->precision)
		{
			f->number->digits = n_char('0', f->flags->precision + 2, &bla);
			f->number->digits[1] = '.';
		}
		else if (f->flags->sharp)
			f->number->digits = ft_strdup("0.");
		else
			f->number->digits = ft_strdup("0");
		return (1);
	}
	else if (number.ld != number.ld)
	{
		f->number->digits = ft_strdup("nan");
		f->number->sign = 0;
		return (1);
	}
	else if (number.ld == HUGE_VALF || number.ld == -HUGE_VALF)
	{
		f->number->digits = ft_strdup(f->flags->conversion == 'f' ? "inf" : "INF");
		return (1);
	}
	return (0);
}

static int		print_nan(t_f *f)
{
	int		len;

	len = f->number->sign ? 4 : 3;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - len, &len);
	else
		f->number->left = n_char(' ', f->flags->width - len, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}

static int		zero_case(char *str, t_f *f)
{
	if (*str == '0' && ft_strlen(str) == 1)
	{
		if (f->flags->sharp && !f->flags->precision)
			f->number->digits = ft_strdup("0.");
		else
			f->number->digits = ft_strdup("0");
		return (1);
	}
	return (0);
}

int		f_case(va_list arg_ptr, t_f *f)
{
	ULL					rank[MAX_RANK];
	t_ext_format		number;
	int					exp;
	char				*str;

	fill_array_by_zero(rank);
	number.ld = get_ld_number(arg_ptr, f);
	get_sign(number.part.sign, f);
	exp = number.part.exponent - 16383 - 63;
	if (!(check_special_numbers(number, f)))
	{
		get_fraction(rank, number.part.fraction);
		multiply(rank, exp);
		if (!(str = convert_to_str(rank, exp)))
			return (0);
		rounding(str, exp, f);
		if (!(zero_case(str, f)))
			put_dot(str, exp, f);
		ft_memdel((void**)&str);
	}
	if (f->number->digits[0] == 'n' || f->number->digits[0] == 'i' ||
			f->number->digits[0] == 'I')
		return (print_nan(f));
	return (f_width_case(f));
}

