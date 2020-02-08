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

int				get_number(va_list arg_ptr, t_f *f)
{
	long long		ll_arg;

	if (f->flags->size == LL)
		ll_arg = va_arg(arg_ptr, long long);
	else if (f->flags->size == L)
		ll_arg = va_arg(arg_ptr, long);
	else if (f->flags->size == H)
		ll_arg = (short)va_arg(arg_ptr, int);
	else if (f->flags->size == HH)
		ll_arg = (char)va_arg(arg_ptr, int);
	else if (f->flags->size == J)
		ll_arg = (intmax_t)va_arg(arg_ptr, intmax_t);
	else if (f->flags->size == Z)
		ll_arg = (ssize_t)va_arg(arg_ptr, ssize_t);
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

void			get_unsigned_number(va_list arg_ptr, t_f *f, int base)
{
	unsigned long long		ull_arg;
	int						reg;

	reg = f->flags->conversion == 'X' ? 1 : 0;
	if (f->flags->size == LL)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->size == L)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->size == H)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->size == HH)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else if (f->flags->size == Z)
		ull_arg = (size_t)va_arg(arg_ptr, size_t);
	else if (f->flags->size == J)
		ull_arg = (uintmax_t)va_arg(arg_ptr, uintmax_t);
	else if (f->flags->size == T)
		ull_arg = (ptrdiff_t)va_arg(arg_ptr, ptrdiff_t);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, base, reg);
}

long double		get_ld_number(va_list arg_ptr, t_f *f)
{
	if (f->flags->size == LD)
		return (va_arg(arg_ptr, long double));
	return ((long double)va_arg(arg_ptr, double));
}

void			get_adress(va_list arg_ptr, t_f *f)
{
	unsigned long long adress;

	adress = (unsigned long long)va_arg(arg_ptr, void*);
	if (!adress && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(adress, 16, 0);
}
