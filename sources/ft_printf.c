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

int		get_flags(char *ptr, t_flags *flags)
{
	int		i = 0;

	if (!ptr[i] || ptr[i] == 'd' || ptr[i] == 's' || ptr[i] == 'c')
		return (0);
	if (ptr[i] == '0')
	{
		flags->zero = 1;
		i++;
	}
	while (ptr[i] && ptr[i] != 'd' && ptr[i] != 's' && ptr[i] != 'c')
	{
		if (ptr[i] == '-')
			flags->minus = 1;
		if (ptr[i] == '+')
			flags->plus = 1;
		if (ptr[i] == ' ')
			flags->space = 1;
		if (ptr[i] >= '1' && ptr[i] <= '9')
		{
			flags->width = ft_atoi(ptr);
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
	flags->space = 0;
}

int		ft_print_int(int arg, t_flags *flags)
{
	if (flags->plus && arg > 0)
	{
		write(1, "+", 1);
		ft_putnbr(arg);
	}
	free_flags(flags);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*ptr;
	t_flags		flags;

	va_start(arg_ptr, format);
	free_flags(&flags);
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr != '%')
			write(1, ptr, 1);
		else
		{
			ptr += get_flags(ptr + 1, &flags);
			if (*ptr == 'd')
				ft_print_int(va_arg(arg_ptr, int), &flags);
			if (*ptr == 's')
				ft_putstr(va_arg(arg_ptr, char*));
			if (*ptr == 'c')
				ft_putchar(va_arg(arg_ptr, int));
		}
		ptr++;
	}
	va_end(arg_ptr);
	return (0);
}
