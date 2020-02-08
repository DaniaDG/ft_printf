/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_sign(int sign, t_f *f)
{
	if (sign < 0)
		f->number->sign = '-';
	else
	{
		if (f->flags->plus)
			f->number->sign = '+';
		else if (f->flags->space)
			f->number->sign = ' ';
	}
}

static void		di_precision_case(t_f *f, int *len)
{
	f->number->zeros = n_char('0', f->flags->precision - *len, len);
	*len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
		f->number->left = n_char(' ', f->flags->width - *len, len);
}

static void		di_only_width_case(t_f *f, int *len)
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

int				di_case(va_list arg_ptr, t_f *f)
{
	int		len;

	fill_sign(get_number(arg_ptr, f), f);
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		di_precision_case(f, &len);
	else
		di_only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}
