/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	x_precision_case(t_f *f, int *len)
{
	f->number->zeros = n_char('0', f->flags->precision - *len, len);
	if (f->flags->conversion == 'p')
	{
		f->number->ox = ft_strdup("0x");
		*len += 2;
	}
	if ((f->flags->conversion == 'x' || f->flags->conversion == 'X')
		&& *(f->number->digits) != '\0' && f->flags->sharp)
	{
		f->number->ox = ft_strdup(f->flags->conversion == 'x' ? "0x" : "0X");
		*len += 2;
	}
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
		f->number->left = n_char(' ', f->flags->width - *len, len);
}

static void	x_only_width_case(t_f *f, int *len)
{
	if (f->flags->conversion == 'p')
	{
		f->number->ox = ft_strdup("0x");
		*len += 2;
	}
	if ((f->flags->conversion == 'x' || f->flags->conversion == 'X')
		&& *(f->number->digits) != '0' && f->flags->sharp)
	{
		f->number->ox = ft_strdup(f->flags->conversion == 'x' ? "0x" : "0X");
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

int			x_case(va_list arg_ptr, t_f *f)
{
	int		len;

	get_unsigned_number(arg_ptr, f, 16);
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		x_precision_case(f, &len);
	else
		x_only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}

int			p_case(va_list arg_ptr, t_f *f)
{
	int		len;

	get_adress(arg_ptr, f);
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		x_precision_case(f, &len);
	else
		x_only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}
