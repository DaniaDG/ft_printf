/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_case(t_f *f, int *len)
{
	f->number->zeros = n_char('0', f->flags->precision - *len, len);
	if (f->flags->conversion == 'p')
		{
			f->number->ox = ft_strdup("0x");
			*len += 2;
		}
	else if (f->flags->sharp)
	{
		if ((f->flags->conversion == 'x' || f->flags->conversion == 'X')
			&& *(f->number->digits) != '\0')
		{
			f->number->ox = ft_strdup(f->flags->conversion == 'x' ? "0x" : "0X");
			*len += 2;
		}
		if (f->flags->conversion == 'o' && !f->number->zeros)
		{
			f->number->ox = ft_strdup("0");
			(*len)++;
		}
	}
	else
		*len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
		f->number->left = n_char(' ', f->flags->width - *len, len);
}

void	only_width_case(t_f *f, int *len)
{
	if (f->flags->conversion == 'p')
		{
			f->number->ox = ft_strdup("0x");
			*len += 2;
		}
	else if (f->flags->sharp && *(f->number->digits) != '0')
	{
		if (f->flags->conversion == 'x' || f->flags->conversion == 'X')
		{
			f->number->ox = ft_strdup(f->flags->conversion == 'x' ? "0x" : "0X");
			*len += 2;
		}
		if (f->flags->conversion == 'o' && !f->number->zeros)
		{
			f->number->ox = ft_strdup("0");
			(*len)++;
		}
	}
	else
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

