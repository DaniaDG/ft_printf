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
	ft_memdel((void**)&(number->left));
	ft_memdel((void**)&(number->ox));
	ft_memdel((void**)&(number->zeros));
	ft_memdel((void**)&(number->digits));
	ft_memdel((void**)&(number->right));
	number->sign = 0;
}



int		get_number(va_list arg_ptr, t_f *f)
{
	long long	ll_arg;
	
	if (f->flags->ll)
		ll_arg = va_arg(arg_ptr, long long);
	else if (f->flags->l)
		ll_arg = va_arg(arg_ptr, long);
	else if (f->flags->h)
		ll_arg = (short)va_arg(arg_ptr, int);
	else if (f->flags->hh)
		ll_arg = (char)va_arg(arg_ptr, int);
	else
		ll_arg = va_arg(arg_ptr, int);
	if (!ll_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_long(ll_arg, 10, 0);
	if (ll_arg < 0)
		return (-1);
	return (1);
}

void		get_unsigned_number(va_list arg_ptr, t_f *f)
{
	unsigned long long		ull_arg;

	if (f->flags->ll)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->l)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->h)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->hh)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, 10, 0);
}

void		get_hex_number(va_list arg_ptr, t_f *f)
{
	int	reg;
	unsigned long long		ull_arg;

	reg = f->flags->conversion == 'X' ? 1 : 0;
	if (f->flags->ll)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->l)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->h)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->hh)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, 16, reg);
}

void		get_oct_number(va_list arg_ptr, t_f *f)
{
	unsigned long long		ull_arg;

	if (f->flags->ll)
		ull_arg = va_arg(arg_ptr, unsigned long long);
	else if (f->flags->l)
		ull_arg = va_arg(arg_ptr, unsigned long);
	else if (f->flags->h)
		ull_arg = (unsigned short)va_arg(arg_ptr, unsigned int);
	else if (f->flags->hh)
		ull_arg = (unsigned char)va_arg(arg_ptr, unsigned int);
	else
		ull_arg = va_arg(arg_ptr, unsigned int);
	if (!ull_arg && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(ull_arg, 8, 0);
}

void	precision_case(t_f *f, int *len)
{
	f->number->zeros = n_char('0', f->flags->precision - *len, len);
	if (f->flags->sharp)
	{
		if ((f->flags->conversion == 'x' || f->flags->conversion == 'X')
			&& *(f->number->digits) != '\0')
		{
			f->number->ox = ft_strdup(f->flags->conversion == 'x' ? "0x" : "0X");
			*len += 2;
		}
		if (f->flags->conversion == 'o' && !f->number->zeros)
		{
			f->number->ox = ft_strdup("0");
			(*len)++;
		}
	}
	else
		*len += f->number->sign ? 1 : 0;
	if (f->flags->minus)
		f->number->right = n_char(' ', f->flags->width - *len, len);
	else
		f->number->left = n_char(' ', f->flags->width - *len, len);
}

void	only_width_case(t_f *f, int *len)
{
	if (f->flags->sharp && *(f->number->digits) != '0')
	{
		if (f->flags->conversion == 'x' || f->flags->conversion == 'X')
		{
			f->number->ox = ft_strdup(f->flags->conversion == 'x' ? "0x" : "0X");
			*len += 2;
		}
		if (f->flags->conversion == 'o' && !f->number->zeros)
		{
			f->number->ox = ft_strdup("0");
			(*len)++;
		}
	}
	else
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
	int				len;
	
	if (f->flags->conversion == 'd' || f->flags->conversion == 'i')
	{
		if (get_number(arg_ptr, f) < 0)
			f->number->sign = '-';
		else
		{
			if (f->flags->plus)
				f->number->sign = '+';
			else if (f->flags->space)
				f->number->sign = ' ';
		}
	}
	if (f->flags->conversion == 'u')
	{
		get_unsigned_number(arg_ptr, f);
		if (f->flags->plus)
				f->number->sign = '+';
			else if (f->flags->space)
				f->number->sign = ' ';
	}
	if (f->flags->conversion == 'x' || f->flags->conversion == 'X')
		get_hex_number(arg_ptr, f);
	if (f->flags->conversion == 'o')
		get_oct_number(arg_ptr, f);
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		precision_case(f, &len);
	else
		only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}
