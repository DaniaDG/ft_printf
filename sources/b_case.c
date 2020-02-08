/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	b_precision_case(t_f *f, int *len)
{
	f->number->zeros = n_char('0', f->flags->precision - *len, len);
	if (f->flags->conversion == 'b' && *(f->number->digits) != '\0' &&
		f->flags->sharp)
	{
		f->number->ox = ft_strdup("0b");
		*len += 2;
	}
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
		f->number->left = n_char(' ', f->flags->width - *len, len);
}

static void	b_only_width_case(t_f *f, int *len)
{
	if (f->flags->conversion == 'b'
		&& *(f->number->digits) != '0' && f->flags->sharp)
	{
		f->number->ox = ft_strdup("0b");
		*len += 2;
	}
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

int			b_case(va_list arg_ptr, t_f *f)
{
	int		len;

	get_unsigned_number(arg_ptr, f, 2);
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		b_precision_case(f, &len);
	else
		b_only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}
