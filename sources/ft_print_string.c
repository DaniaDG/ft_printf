/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:34:18 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:34:19 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


int		ft_print_string(va_list arg_ptr, t_f *f)
{
	int			len;
	char		*tmp;

	if (!(tmp = va_arg(arg_ptr, char*)))
		tmp = ft_strdup("(null)");
	if (f->flags->dot)
	{
		if (!f->flags->precision)
			len = 0;
		else
		{
			f->string->str = ft_strsub(tmp, 0, ft_min(f->flags->precision, ft_strlen(tmp)));
			len = ft_strlen(f->string->str);
		}
	}
	else
	{
		f->string->str = ft_strdup(tmp);
		len = ft_strlen(f->string->str);
	}
	if (f->flags->minus)
		f->string->right = n_char(' ', f->flags->width - len, &len);
	else
		f->string->left = n_char(' ', f->flags->width - len, &len);
	print_and_free_string_struct(f->string);
	free_flags(f->flags);
	return (len);
}
