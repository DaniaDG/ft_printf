/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:34:18 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:34:19 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_case(va_list arg_ptr, t_f *f)
{
	int			len;
	char		*tmp;

	if (!(tmp = (char*)va_arg(arg_ptr, char*)))
		f->string->str = ft_strdup("(null)");
	else
		f->string->str = ft_strdup(tmp);
	if (f->flags->dot && f->flags->precision < (int)ft_strlen(f->string->str))
		f->string->str[f->flags->precision] = 0;
	len = ft_strlen(f->string->str);
	if (f->flags->minus)
		f->string->right = n_char(' ', f->flags->width - len, &len);
	else
		f->string->left = n_char(' ', f->flags->width - len, &len);
	print_and_free_string_struct(f->string);
	free_flags(f->flags);
	return (len);
}
