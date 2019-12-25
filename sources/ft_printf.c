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
		if (ptr[i] >= '1' && ptr[i] <= '9')
		{
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

int		ft_print_int(int arg, t_flags *flags)
{
	int		len;

	len = ft_intlen(arg);
		if (arg >= 0)
		{
			if (flags->zero && flags->plus && !flags->minus)
			{
				write(1, "+", 1);
				ft_print_nchar('0', flags->width - len - 1);
				ft_putnbr(arg);
			}
			else if (!flags->zero && flags->plus && !flags->minus)
			{
				ft_print_nchar(' ', flags->width - len - 1);
				write(1, "+", 1);
				ft_putnbr(arg);
			}
			else if (!flags->zero && flags->plus && flags->minus)
			{
				ft_putnbr(flags->width);
				write(1, "blabla\n", 7);
				write(1, "+", 1);
				ft_putnbr(arg);
				ft_print_nchar(' ', flags->width - len - 1);	
			}
			else if (!flags->zero && !flags->plus && flags->minus && flags->space)
			{
				write(1, " ", 1);
				ft_putnbr(arg);
				ft_print_nchar(' ', flags->width - len - 1);
			}
			else if (!flags->zero && !flags->plus && !flags->minus)
			{
				ft_print_nchar(' ', flags->width - len);
				ft_putnbr(arg);
			}
		}
		else
		{
			if (flags->zero && !flags->space)
			{
				write(1, "-", 1);
				ft_print_nchar('0', flags->width - len - 1);
				if (arg == -2147483648)
					write (1, "2147483648", 10);
				else
					ft_putnbr(-arg);
			}
			else if (!flags->zero)
			{
				ft_print_nchar(' ', flags->width - len - 1);
				ft_putnbr(arg);
			}
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
				ft_print_int(va_arg(arg_ptr,int), &flags);
		}
		ptr++;
	}
	va_end(arg_ptr);
	return (0);
}
