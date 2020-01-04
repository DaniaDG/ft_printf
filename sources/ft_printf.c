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
	if (ft_strchr("discouxX", ptr[i]))
		return (1);
	while (ptr[i] && ft_strchr("hl0123456789 .+-#", ptr[i]))
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
			flags->dot = 1;
		if (ptr[i] == '#' && ptr[i - 1] == '%')
			flags->sharp = 1;
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
		if (ptr[i] == 'h')
		{
			flags->h = 1;
			if (ptr[i - 1] == 'h')
			{
				flags->hh = 1;
				flags->h = 0;
			}
		}
		if (ptr[i] == 'l')
		{
			flags->l = 1;
			if (ptr[i - 1] == 'l')
			{
				flags->ll = 1;
				flags->l = 0;
			}
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
	flags->sharp = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->conversion = 0;
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

void	init_f(t_f *f)
{
	f->flags = (t_flags*)malloc(sizeof(t_flags));
	free_flags(f->flags);
	f->string = (t_string*)malloc(sizeof(t_string));
	f->string->left = NULL;
	f->string->str = NULL;
	f->string->right = NULL;
	f->number = (t_integer*)malloc(sizeof(t_integer));
	f->number->sign = 0;
	f->number->ox = NULL;
	f->number->left = NULL;
	f->number->right = NULL;
	f->number->digits = NULL;
	f->number->zeros = NULL;
}

int		ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*ptr;
	t_f			f;
	int			res = 0;
	char		*tmp;
	
	va_start(arg_ptr, format);
	init_f(&f);
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
			ptr += get_flags(ptr + 1, f.flags);
			f.flags->conversion = *ptr;
			if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u'|| *ptr == 'o' || *ptr == 'x' || *ptr == 'X')
				res += ft_print_int(arg_ptr, &f);	
			if (*ptr == 's')
			{
				if (!(tmp = va_arg(arg_ptr, char*)))
					tmp = ft_strdup("(null)");
				res += ft_print_string(tmp, f.flags);
			}
			if (*ptr == 'c')
				res += ft_print_char(va_arg(arg_ptr, int), f.flags);
		}
		ptr++;
	}
	va_end(arg_ptr);
	return (res);
}
