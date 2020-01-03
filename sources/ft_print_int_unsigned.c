/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:33:45 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:33:47 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_and_free_int_struct(t_integer *number)
{
	if (number->left)
		write(1, number->left, ft_strlen(number->left));
	if (number->sign)
		write(1, &(number->sign), 1);
	if (number->zeros)
		write(1, number->zeros, ft_strlen(number->zeros));
	if (number->digits)
		write(1, number->digits, ft_strlen(number->digits));
	if (number->right)
		write(1, number->right, ft_strlen(number->right));
	//free all struct!!!
}

int		ft_print_int_unsigned(va_list arg_ptr, t_flags *flags)
{
	t_integer	number;
	int			len;
	unsigned int			u_int_arg;
	unsigned long			u_long_arg;
	unsigned long long		u_long_long_arg;
	unsigned short			u_short_arg = 0;
	unsigned char			u_short_short_arg = 0;

	number.sign = 0;
	number.left = NULL;
	number.right = NULL;
	number.digits = NULL;
	number.zeros = NULL;
	if (flags->ll)
	{
		u_long_long_arg = (unsigned long long)va_arg(arg_ptr, unsigned long long);
		number.digits = ft_itoa_base_long(u_long_long_arg, 10);
	}
	else if (flags->l)
	{
		u_long_arg = (unsigned long)va_arg(arg_ptr, unsigned long);
		number.digits = ft_itoa_base_long(u_long_arg, 10);
	}
	else if (flags->h)
	{
		u_short_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
		number.digits = ft_itoa_base(u_short_arg, 10);
	}
	else if (flags->hh)
	{
		u_short_short_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
		number.digits = ft_itoa_base(u_short_short_arg, 10);
	}
	else
	{
		u_int_arg = (unsigned int)va_arg(arg_ptr, unsigned int);
		number.digits = ft_itoa_base(u_int_arg, 10);
	}
	if (flags->plus)
		number.sign = '+';
	else if (flags->space)
		number.sign = ' ';
	//
	len = ft_strlen(number.digits);
	if (flags->dot)
	{
		number.zeros = n_char('0', flags->precision - len, &len);
		len += number.sign ? 1 : 0;
		if (flags->minus)
			number.right = n_char(' ', flags->width - len, &len);
		else
			number.left = n_char(' ', flags->width - len, &len);
	}
	else
	{
		len += number.sign ? 1 : 0;
		if (flags->minus)
			number.right = n_char(' ', flags->width - len, &len);
		else
		{
			if (flags->zero)
				number.zeros = n_char('0', flags->width - len, &len);
			else
				number.left = n_char(' ', flags->width - len, &len);
		}
	}
	print_and_free_int_struct(&number);
	free_flags(flags);
	return (len);
}
