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
	char		c = 92;

	va_start(arg_ptr, format);
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr != '%' && *ptr != '\\')
			write(1, ptr, 1);
		else if (*ptr == 92)
		{
			ptr++;
			if (*ptr == 'n')
				write(1, "\n", 1);
			if (*ptr == 't')
				write(1, "\t", 1);
			if (*ptr == 'v')
				write(1, "\v", 1);
			if (*ptr == 92)
				write(1, &c, 1);
			if (*ptr == '\"')
				write(1, "\"", 1);
			if (*ptr == '\'')
				write(1, "\'", 1);
			if (*ptr == '\b')
				write(1, "\b", 1);
			if (*ptr == '\r')
				write(1, "\r", 1);
		}
		else if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'd')
				ft_putnbr(va_arg(arg_ptr, int));
			if (*ptr == 'c')
				ft_putchar(va_arg(arg_ptr, int));
			if (*ptr == 's')
				ft_putstr(va_arg(arg_ptr, char*));
			if (*ptr == '%')
				write(1, "%", 1);
		}
		ptr++;
	}
	va_end(arg_ptr);
	return (0);
}
