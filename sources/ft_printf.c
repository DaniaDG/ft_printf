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
#include <stdio.h>

int		get_flags(char *ptr, t_flags *flags)
{
	int		i = 0;

	if (!ptr[i])
		return (0);
	if (ptr[i] == 'd' || ptr[i] == 's' || ptr[i] == 'c')
		return (1);
	while (ptr[i] && ptr[i] != 'd' && ptr[i] != 's' && ptr[i] != 'c')
	{
		if (ptr[i] == '0')
			flags->zero = 1;
		if (ptr[i] == '-')
			flags->minus = 1;
		if (ptr[i] == '+')
			flags->plus = 1;
		if (ptr[i] == ' ')
			flags->space = 1;
		if (ptr[i] == '.')
		{
			flags->dot = 1;
			if (ptr[i + 1])
			{
				if (ptr[i + 1] == '0')
					flags->precision = -1;
			}
		}
		if (ptr[i] >= '1' && ptr[i] <= '9')
		{
			if (flags->dot)
				flags->precision = ft_atoi(&ptr[i]);
			else
				flags->width = ft_atoi(&ptr[i]);
			while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
				i++;
			i--;
		}
		i++;
	}
	return (i + 1);
}

void	free_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->space = 0;
}

int		ft_intlen(int n)
{
	int len = 0;

	if (!n)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_print_nchar(char c, int i)
{
	while (i-- > 0)
		write(1, &c, 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*ptr;
	t_flags		flags;
	int			res = 0;
	
	va_start(arg_ptr, format);
	free_flags(&flags);
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			res++;
		}
		else
		{
			ptr += get_flags(ptr + 1, &flags);
			if (*ptr == 'd')
				res += ft_print_int(va_arg(arg_ptr,int), &flags);
			if (*ptr == 's')
				res += ft_print_string(va_arg(arg_ptr, char*), &flags);
		}
		ptr++;
	}
	va_end(arg_ptr);
	return (res);
}
