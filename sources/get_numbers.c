/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:01:32 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 17:01:33 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_number(va_list arg_ptr, t_f *f)
{
	long long		ll_arg;

	if (f->flags->ll)
		ll_arg = va_arg(arg_ptr, long long);
	else if (f->flags->l)
		ll_arg = va_arg(arg_ptr, long);
	else if (f->flags->h)
		ll_arg = (short)va_arg(arg_ptr, int);
	else if (f->flags->hh)
		ll_arg = (char)va_arg(arg_ptr, int);
	else
		ll_arg = va_arg(arg_ptr, int);
	if (!ll_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_long(ll_arg, 10, 0);
	if (ll_arg < 0)
		return (-1);
	return (1);
}

void		get_unsigned_number(va_list arg_ptr, t_f *f)
{
	unsigned long long		ull_arg;

	if (f->flags->ll)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->l)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->h)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->hh)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, 10, 0);
}

void		get_hex_number(va_list arg_ptr, t_f *f)
{
	int						reg;
	unsigned long long		ull_arg;

	reg = f->flags->conversion == 'X' ? 1 : 0;
	if (f->flags->ll)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->l)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->h)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->hh)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, 16, reg);
}

void		get_oct_number(va_list arg_ptr, t_f *f)
{
	unsigned long long		ull_arg;

	if (f->flags->ll)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->l)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->h)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->hh)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, 8, 0);
}
