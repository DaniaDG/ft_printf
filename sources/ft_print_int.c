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

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*n_char(char c, int n, int *len)
{
	char	*str;
	int		tmp;

	if (n <= 0)
		return (NULL);
	tmp = n;
	str = (char *)malloc(sizeof(char) * (n + 1));
	str[n--] = '\0';
	while (n >= 0)
		str[n--] = c;
	*len = *len + tmp;
	return (str);
}

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

int		ft_print_int(va_list arg_ptr, t_flags *flags)
{
	t_integer	number;
	int			len;
	int			int_arg = 0;
	long		long_arg = 0;
	long long	long_long_arg = 0;
	short		short_arg = 0;
	char		short_short_arg = 0;

	number.sign = 0;
	number.ox = NULL;
	number.left = NULL;
	number.right = NULL;
	number.digits = NULL;
	number.zeros = NULL;
	if (flags->ll)
	{
		long_long_arg = (long long)va_arg(arg_ptr, long long);
		number.digits = ft_itoa_base_long(long_long_arg, 10);
	}
	else if (flags->l)
	{
		long_arg = (long)va_arg(arg_ptr, long);
		number.digits = ft_itoa_base_long(long_arg, 10);
	}
	else if (flags->h)
	{
		short_arg = (short)va_arg(arg_ptr, int);
		number.digits = ft_itoa_base(short_arg, 10);
	}
	else if (flags->hh)
	{
		short_short_arg = (char)va_arg(arg_ptr, int);
		number.digits = ft_itoa_base(short_short_arg, 10);
	}
	else
	{
		int_arg = va_arg(arg_ptr, int);
		number.digits = ft_itoa_base(int_arg, 10);
	}
	if (int_arg < 0 || long_arg < 0 || long_long_arg < 0 || short_short_arg < 0 || short_arg < 0)
		number.sign = '-';
	else
	{
		if (flags->plus)
			number.sign = '+';
		else if (flags->space)
			number.sign = ' ';
	}
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
