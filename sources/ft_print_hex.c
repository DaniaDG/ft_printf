/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
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
	if (number->ox)
		write(1, number->ox, ft_strlen(number->ox));
	if (number->zeros)
		write(1, number->zeros, ft_strlen(number->zeros));
	if (number->digits)
		write(1, number->digits, ft_strlen(number->digits));
	if (number->right)
		write(1, number->right, ft_strlen(number->right));
	//free all struct!!!
}

int		ft_print_hex(va_list arg_ptr, t_flags *flags)
{
	t_integer	number;
	int			len;
	int						int_arg = 0;
	long					long_arg = 0;
	long long				long_long_arg = 0;
	short					short_arg = 0;
	char					short_short_arg = 0;

	number.sign = 0;
	number.ox = NULL;
	number.left = NULL;
	number.right = NULL;
	number.digits = NULL;
	number.zeros = NULL;
	if (flags->ll)
	{
		long_long_arg = (long long)va_arg(arg_ptr, long long);
		if (long_long_arg < 0)
			number.digits = ft_itoa_base_unsigned((unsigned long long)long_long_arg, 16);
		else
			number.digits = ft_itoa_base_long(long_long_arg, 16);
	}
	else if (flags->l)
	{
		long_arg = (long)va_arg(arg_ptr, long);
		if (long_arg < 0)
			number.digits = ft_itoa_base_unsigned((unsigned long)long_arg, 16);
		else
			number.digits = ft_itoa_base_long(long_arg, 16);
	}
	else if (flags->h)
	{
		short_arg = (short)va_arg(arg_ptr, int);
		if (short_arg < 0)
			number.digits = ft_itoa_base_unsigned((unsigned short)short_arg, 16);
		else
			number.digits = ft_itoa_base_long(short_arg, 16);
	}
	else if (flags->hh)
	{
		short_short_arg = (char)va_arg(arg_ptr, int);
		if (short_short_arg < 0)
			number.digits = ft_itoa_base_unsigned((unsigned char)short_short_arg, 16);
		else
			number.digits = ft_itoa_base(short_short_arg, 16);
	}
	else
	{
		int_arg = va_arg(arg_ptr, int);
		if (int_arg < 0)
			number.digits = ft_itoa_base_unsigned((unsigned int)int_arg, 16);
		else
			number.digits = ft_itoa_base(int_arg, 16);
	}
	//
	len = ft_strlen(number.digits);
	if (flags->dot)
	{
		number.zeros = n_char('0', flags->precision - len, &len);
		if (flags->sharp && (int_arg || long_arg || long_long_arg || short_arg || short_short_arg))
		{
			number.ox = ft_strdup(flags->conversion == 'X' ? "0X" : "0x");
			len += 2;
		}
		if (flags->minus)
			number.right = n_char(' ', flags->width - len, &len);
		else
			number.left = n_char(' ', flags->width - len, &len);
	}
	else
	{
		if (flags->sharp && (int_arg || long_arg || long_long_arg || short_arg || short_short_arg))
		{
			number.ox = ft_strdup(flags->conversion == 'X' ? "0X" : "0x");
			len += 2;
		}
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
