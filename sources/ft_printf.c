/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:59:16 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/23 10:59:17 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse(char *ptr, va_list arg_ptr, t_f *f)
{
	int		i;

	while (*ptr)
	{
		i = 0;
		while (*ptr != '%' && *ptr)
		{
			i++;
			ptr++;
			f->res++;
		}
		write(1, ptr - i, i);
		if (*ptr == '%')
		{
			ptr += get_flags(ptr + 1, f->flags, arg_ptr) + 1;
			if (f->flags->conversion == '\0')
				break ;
			f->res += ft_print_argument(arg_ptr, f);
		}
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*ptr;
	t_f			f;

	va_start(arg_ptr, format);
	init_f(&f);
	ptr = (char *)format;
	parse(ptr, arg_ptr, &f);
	va_end(arg_ptr);
	free_all(&f);
	return (f.res);
}
