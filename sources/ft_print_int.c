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

char	*n_zeros(int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	while (len--)
		str[len] = '0';
	return (str);
}

int		ft_print_int(int arg, t_flags *flags)
{
	t_integer	number;
	int			len;

	//getting sign of a number

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
	len = ft_strlen(num);
	if (flags->precision > len)
		number.zeros = n_zeros(flags->precision - len)




	//len = ft_strlen(num) + (number.sign == '-' || number.sign == '+' || number.sign == ' ' ? 1 : 0);
}


/*int		ft_print_int(int arg, t_flags *flags)
{
	int		len;
	int		field;
	char	*num;
	char	*str;
	char	*tmp;
	char	sign;
	

	num = ft_itoa_base(ft_abs(arg), 10);
	if (arg == 0 && flags->precision == -1)
		len == 0;
	else
		len = ft_strlen(num);
	field = ft_max(ft_max(flags->width, flags->precision), len + (flags->plus | flags->space));
	str = (char *)malloc(sizeof(char) * (field + 1));
	str[len] = '\0';
	if (arg >= 0)
	{
		if (flags->precision >= len)
		{
			tmp = n_zeros(flags->precision - len)
		}
	}



}*/







/*int		ft_print_int(int arg, t_flags *flags)
{
	int		len;
	int		n = 0;

	len = ft_intlen(arg);
		if (arg >= 0)
		{
			if (flags->zero && flags->plus && !flags->minus)
			{
				write(1, "+", 1);
				ft_print_nchar('0', flags->width - len - 1);
				ft_putnbr(arg);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
			if (flags->zero && !flags->plus && !flags->minus)
			{
				ft_print_nchar('0', flags->width - len);
				ft_putnbr(arg);
				n = flags->width - len <= 0 ? 0 : flags->width - len;
				n = n + len;
			}
			else if (!flags->zero && flags->plus && !flags->minus)
			{
				ft_print_nchar(' ', flags->width - len - 1);
				write(1, "+", 1);
				ft_putnbr(arg);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
			else if (!flags->zero && flags->plus && flags->minus)
			{
				write(1, "+", 1);
				ft_putnbr(arg);
				ft_print_nchar(' ', flags->width - len - 1);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;	
			}
			else if (!flags->zero && !flags->plus && flags->minus && flags->space)
			{
				write(1, " ", 1);
				ft_putnbr(arg);
				ft_print_nchar(' ', flags->width - len - 1);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
			else if (!flags->zero && !flags->plus && flags->minus && !flags->space)
			{
				ft_putnbr(arg);
				ft_print_nchar(' ', flags->width - len);
				n = flags->width - len <= 0 ? 0 : flags->width - len;
				n = n + len;
			}
			else if (!flags->zero && !flags->plus && !flags->minus && flags->space)
			{
				write(1, " ", 1);
				ft_print_nchar(' ', flags->width - len - 1);
				ft_putnbr(arg);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
			else if (!flags->zero && !flags->plus && !flags->minus)
			{
				ft_print_nchar(' ', flags->width - len);
				ft_putnbr(arg);
				n = flags->width - len <= 0 ? 0 : flags->width - len;
				n = n + len;
			}
		}
		else
		{
			if (flags->zero)
			{
				write(1, "-", 1);
				ft_print_nchar('0', flags->width - len - 1);
				if (arg == -2147483648)
					write (1, "2147483648", 10);
				else
					ft_putnbr(-arg);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
			else if (!flags->zero && !flags->minus)
			{
				ft_print_nchar(' ', flags->width - len - 1);
				ft_putnbr(arg);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
			else if (!flags->zero && flags->minus)
			{
				ft_putnbr(arg);
				ft_print_nchar(' ', flags->width - len - 1);
				n = flags->width - len - 1 <= 0 ? 0 : flags->width - len - 1;
				n = 1 + n + len;
			}
		}
	free_flags(flags);
	return (n);
}*/
