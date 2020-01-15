/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mult(long *m1, long *m2);

int		ld_len(long double number)
{
	int len;

	len = 0;
	while (number > 1.0)
	{
		number /= 10;
		len++;
	}
	printf("ld_len = %d\n", len);
	return (len);
}

int		multiply(va_list arg_ptr, t_f *f)
{
	unsigned long long	tmp;
	union union_type	number;
	long				rank[50];
	long				power[50];

	int i = 0;
	while (i < 50)
	{
		rank[i] = 0;
		power[i] = 0;
		i++;
	}
	number.ld = va_arg(arg_ptr, long double);
	tmp = number.part.fraction;
	i = 1;
	while (tmp)
	{
		rank[i++] = tmp % 10000;
		tmp = tmp / 10000;
	}

	int exp = number.part.exponent - 16383 - 63;
	power[1] = 1;
	if (exp > 0)
	{
		while (exp)
		{
			i = 1;
			while (i < 25)
			{
				power[i] *= 2;
				power[i] += power[i - 1] / 10000;
				power[i - 1] = power[i - 1] % 10000;
				i++;
			}
			exp--;
		}
	}
	if (exp < 0)
	{
		exp *= -1;
		while (exp)
		{
			i = 1;
			while (i < 25)
			{
				power[i] *= 5;
				power[i] += power[i - 1] / 10000;
				power[i - 1] = power[i - 1] % 10000;
				i++;
			}
			exp--;
		}
	}
	mult(rank, power);
	int len = 0;
	while (!rank[i])
		i--;
	int k = 1;
	while (rank[i] / k)
	{
		len++;
		k *= 10;
	}
	len += i * 4;
	//printf("len = %d\n", len);
	char	*str;
	char	*tmp_str;
	str = (char *)malloc(sizeof(char) * (len + 2));
	tmp_str = str;
	str[len + 1] = 0;
	*str++ = '0';
	k = 1000;
	while (rank[i] / k == 0)
		k /= 10;
	if (!k)
		i--;
	while (i > 0)
	{
		if (!k)
			k = 1000;
		while (k)
		{
			*str = rank[i] / k + '0';
			rank[i] %= k;
			str++;
			k /= 10;
		}
		i--;
	}
	
	exp = number.part.exponent - 16383 - 63;
	if (exp < 0)
	{
		if ((i = ft_strlen(++tmp_str) + exp) < 0)
		{
			write(1, "0.", 2);
			while (i++ <= 0)
				write(1, "0", 1);
			write(1, tmp_str, ft_strlen(tmp_str));
		}
		else
		{
			if (f->flags->precision)
				rounding(tmp_str + i + f->flags->precision);
			else
				rounding(tmp_str + i + 6);
			if (*(tmp_str - 1) != '0')
				write(1, tmp_str - 1, 1);
			write(1, tmp_str, i);
			write(1, ".", 1);
			write(1, &tmp_str[i], ft_strlen(&tmp_str[i]));
		}
	}
	else if (exp > 0)
	{
		i = ft_strlen(++tmp_str);
		write(1, tmp_str, i);
		write(1, ".", 1);
		//write(1, &tmp_str[i], ft_strlen(&tmp_str[i]));
	}
	else
	{
		if (f->flags->precision)
			rounding(tmp_str + i + f->flags->precision);
		else
			rounding(tmp_str + i + 6);
		write(1, tmp_str, 1);
		write(1, ".", 1);
		write(1, &tmp_str[i + 1], ft_strlen(&tmp_str[i + 1]));
	}
	free_flags(f->flags);
	i = 30;
	while (i > 0)
		ft_printf("%04ld", rank[i--]);
	return (0);
}
