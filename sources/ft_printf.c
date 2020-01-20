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

int		ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*ptr;
	t_f			f;
	int			res = 0;

	
	va_start(arg_ptr, format);
	init_f(&f);
	ptr = (char *)format;
	if (*ptr == '%' && *(ptr + 1) == '\0')
		return (0) ;
	while (*ptr)
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			res++;
		}
		else
		{
			ptr += get_flags(ptr + 1, f.flags);
			if (!(f.flags->conversion = *ptr))
				break ;
			if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u'|| *ptr == 'o' || *ptr == 'x' || *ptr == 'X')
				res += ft_print_int(arg_ptr, &f);	
			else if (*ptr == 's')
				res += ft_print_string(arg_ptr, &f);
			else if (*ptr == 'c' || *ptr == '%')
				res += ft_print_char(arg_ptr, &f);
			else if (*ptr == 'p')
				res += p_case(arg_ptr, &f);
			else if (*ptr == 'f')
			{
				if (!f.flags->precision && f.flags->conversion == 'f' && !f.flags->dot)
					f.flags->precision = 6;
				res += f_case(arg_ptr, &f);
			}
			else
			{
				write(1, ptr, 1);
				res++;
				free_flags(f.flags);
			}
		}
		ptr++;
	}
	va_end(arg_ptr);
	ft_memdel((void**)&(f.number));
	ft_memdel((void**)&(f.f_number));
	ft_memdel((void**)&(f.string));
	ft_memdel((void**)&(f.character));
	return (res);
}
