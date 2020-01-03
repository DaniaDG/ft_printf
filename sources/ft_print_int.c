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



int		get_number(va_list arg_ptr, t_size_number *num, t_f *f)
{
	if (f->flags->ll)
	{
		num->long_long_arg = (long long)va_arg(arg_ptr, long long);
		f->number->digits = ft_itoa_base_long(num->long_long_arg, 10, 0);
	}
	else if (f->flags->l)
	{
		num->long_arg = (long)va_arg(arg_ptr, long);
		f->number->digits = ft_itoa_base_long(num->long_arg, 10, 0);
	}
	else if (f->flags->h)
	{
		num->short_arg = (short)va_arg(arg_ptr, int);
		f->number->digits = ft_itoa_base(num->short_arg, 10, 0);
	}
	else if (f->flags->hh)
	{
		num->short_short_arg = (char)va_arg(arg_ptr, int);
		f->number->digits = ft_itoa_base(num->short_short_arg, 10, 0);
	}
	else
	{
		num->int_arg = va_arg(arg_ptr, int);
		f->number->digits = ft_itoa_base(num->int_arg, 10, 0);
	}
	if (num->int_arg < 0 || num->long_arg < 0 || num->long_long_arg < 0 
		|| num->short_short_arg < 0 || num->short_arg < 0)
		return (-1);
	return (1);
}

void		get_unsigned_number(va_list arg_ptr, t_size_number *num, t_f *f)
{
	if (f->flags->ll)
	{
		num->u_long_long_arg = (unsigned long long)va_arg(arg_ptr, unsigned long long);
		f->number->digits = ft_itoa_base_unsigned(num->u_long_long_arg, 10, 0);
	}
	else if (f->flags->l)
	{
		num->u_long_arg = (unsigned long)va_arg(arg_ptr, unsigned long);
		f->number->digits = ft_itoa_base_long(num->u_long_arg, 10, 0);
	}
	else if (f->flags->h)
	{
		num->u_short_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
		f->number->digits = ft_itoa_base(num->u_short_arg, 10, 0);
	}
	else if (f->flags->hh)
	{
		num->u_short_short_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
		f->number->digits = ft_itoa_base(num->u_short_short_arg, 10, 0);
	}
	else
	{
		num->u_int_arg = va_arg(arg_ptr, unsigned int);
		f->number->digits = ft_itoa_base(num->u_int_arg, 10, 0);
	}
}

void		get_hex_number(va_list arg_ptr, t_size_number *num, t_f *f)
{
	int	reg;

	reg = f->flags->conversion == 'X' ? 1 : 0;
	//printf("\nreg = ")
	if (f->flags->ll)
	{
		num->long_long_arg = (long long)va_arg(arg_ptr, long long);
		if (num->long_long_arg < 0)
			f->number->digits = ft_itoa_base_unsigned((unsigned long long)num->long_long_arg, 16, reg);
		else
			f->number->digits = ft_itoa_base_long(num->long_long_arg, 16, reg);
	}
	else if (f->flags->l)
	{
		num->long_arg = (long)va_arg(arg_ptr, long);
		if (num->long_arg < 0)
			f->number->digits = ft_itoa_base_unsigned((unsigned long)num->long_arg, 16, reg);
		else
			f->number->digits = ft_itoa_base_long(num->long_arg, 16, reg);
	}
	else if (f->flags->h)
	{
		num->short_arg = (short)va_arg(arg_ptr, int);
		if (num->short_arg < 0)
			f->number->digits = ft_itoa_base_unsigned((unsigned short)num->short_arg, 16, reg);
		else
			f->number->digits = ft_itoa_base_long(num->short_arg, 16, reg);
	}
	else if (f->flags->hh)
	{
		num->short_short_arg = (char)va_arg(arg_ptr, int);
		if (num->short_short_arg < 0)
			f->number->digits = ft_itoa_base_unsigned((unsigned char)num->short_short_arg, 16, reg);
		else
			f->number->digits = ft_itoa_base(num->short_short_arg, 16, reg);
	}
	else
	{
		num->int_arg = va_arg(arg_ptr, int);
		if (num->int_arg < 0)
			f->number->digits = ft_itoa_base_unsigned((unsigned int)num->int_arg, 16, reg);
		else
			f->number->digits = ft_itoa_base(num->int_arg, 16, reg);
	}
}


void	fill_by_zero(t_size_number *num)
{
	num->int_arg = 0;
	num->long_arg = 0;
	num->long_long_arg = 0;
	num->short_arg = 0;
	num->short_short_arg = 0;
	num->u_int_arg = 0;
	num->u_long_arg = 0;
	num->u_long_long_arg = 0;
	num->u_short_arg = 0;
	num->u_short_short_arg = 0;
}

void	precision_case(t_f *f, int *len)
{
	f->number->zeros = n_char('0', f->flags->precision - *len, len);
	*len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
		f->number->left = n_char(' ', f->flags->width - *len, len);
}

void	only_width_case(t_f *f, int *len)
{
	*len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
	{
		if (f->flags->zero)
			f->number->zeros = n_char('0', f->flags->width - *len, len);
		else
			f->number->left = n_char(' ', f->flags->width - *len, len);
	}
}


int		ft_print_int(va_list arg_ptr, t_f *f)
{
	t_size_number	num;
	int				len;
	
	fill_by_zero(&num);
	if (f->flags->conversion == 'd' || f->flags->conversion == 'i')
	{
		if (get_number(arg_ptr, &num, f) < 0)
			f->number->sign = '-';
	}
	if (f->flags->conversion == 'u')
		get_unsigned_number(arg_ptr, &num, f);
	if (f->flags->conversion == 'x' || f->flags->conversion == 'X')
		get_hex_number(arg_ptr, &num, f);
	else
	{
		if (f->flags->plus)
			f->number->sign = '+';
		else if (f->flags->space)
			f->number->sign = ' ';
	}
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		precision_case(f, &len);
	else
		only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}
