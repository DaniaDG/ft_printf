/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flags_check(char *ptr, t_flags *flags, va_list arg_ptr)
{
	if (*ptr == '0' && !flags->dot)
		flags->zero = 1;
	if (*ptr == '-')
		flags->minus = 1;
	if (*ptr == '+')
		flags->plus = 1;
	if (*ptr == ' ')
		flags->space = 1;
	if (*ptr == '.')
		flags->dot = 1;
	if (*ptr == '#')
		flags->sharp = 1;
	if (*ptr == '*' && !flags->dot)
		flags->width = va_arg(arg_ptr, int);
	if (*ptr == '*' && flags->dot)
		flags->precision = va_arg(arg_ptr, int);
}

static void		size_check(char *ptr, t_flags *flags)
{
	if (*ptr == 'h' && *(ptr - 1) != 'h')
		flags->size = H;
	if (*ptr == 'h' && *(ptr - 1) == 'h')
		flags->size = HH;
	if (*ptr == 'l' && *(ptr - 1) != 'l')
		flags->size = L;
	if (*ptr == 'l' && *(ptr - 1) == 'l')
		flags->size = LL;
	if (*ptr == 'L')
		flags->size = LD;
	if (*ptr == 'z')
		flags->size = Z;
	if (*ptr == 'j')
		flags->size = J;
	if (*ptr == 't')
		flags->size = T;
}

static int		wp_check(char *ptr, t_flags *flags)
{
	int		i;

	i = 0;
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
	return (i);
}

int				get_flags(char *ptr, t_flags *flags, va_list arg_ptr)
{
	int		i;

	i = 0;
	if (!ptr[i])
		return (0);
	while (ptr[i] && ft_strchr("Lhzjtl0123456789 .+-#*", ptr[i]))
	{
		flags_check(&ptr[i], flags, arg_ptr);
		i += wp_check(&ptr[i], flags);
		size_check(&ptr[i], flags);
		i++;
	}
	if (ft_strchr("%fcspdiouxXbn", ptr[i]))
		flags->conversion = ptr[i];
	if (!flags->precision && flags->conversion == 'f' && !flags->dot)
		flags->precision = 6;
	return (i + 1);
}
