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

int		ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
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

void	print_and_free_int_struct(t_integer *number)
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

int		ft_print_int(int arg, t_flags *flags)
{
	t_integer	number;
	int			len;

	number.sign = 0;
	number.left = NULL;
	number.right = NULL;
	number.digits = NULL;
	number.zeros = NULL;
	if (arg < 0)
		number.sign = '-';
	else
	{
		if (flags->plus)
			number.sign = '+';
		else if (flags->space)
			number.sign = ' ';
	}
	//
	number.digits = ft_itoa_base(ft_abs(arg), 10);
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
	return (len);
}
