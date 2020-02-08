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

int				f_case(va_list arg_ptr, t_f *f)
{
	unsigned long long	rank[MAX_RANK];
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
