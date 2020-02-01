/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:23:41 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/03 13:23:42 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(va_list arg_ptr, t_f *f)
{
	int				len;

	len = 1;
	if (f->flags->conversion == '%' || !f->flags->conversion)
		f->character->c = f->flags->conversion;
	else
		f->character->c = (char)va_arg(arg_ptr, int);
	if (f->flags->minus)
		f->character->right = n_char(' ', f->flags->width - 1, &len);
	else if (f->flags->zero)
		f->character->left = n_char('0', f->flags->width - 1, &len);
	else
		f->character->left = n_char(' ', f->flags->width - 1, &len);
	print_and_free_char_struct(f->character);
	free_flags(f->flags);
	return (len);
}
