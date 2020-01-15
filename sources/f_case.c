/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_array_by_zero(long *rank, long *power)
{
	int		i;

	i = 0;
	while (i < 50)
	{
		rank[i] = 0;
		power[i] = 0;
		i++;
	}
}

void	get_fraction(long *rank, unsigned long long fraction)
{
	int		i;

	i = 1;
	while (fraction)
	{
		rank[i++] = fraction % 10000;
		fraction = fraction / 10000;
	}
}

void	get(long *power, int exp)
{
	int		i;

	power[1] = 1;
	if (exp > 0)
	{
		while (exp)
		{
			i = 1;
			while (i < 50)
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
			while (i < 50)
			{
				power[i] *= 5;
				power[i] += power[i - 1] / 10000;
				power[i - 1] = power[i - 1] % 10000;
				i++;
			}
			exp--;
		}
	}
}

int		f_case(va_list arg_ptr, t_f *f)
{
	long				rank[50];
	long				power[50];
	union union_type	number;
	unsigned long long	tmp;
	int					exp;

	fill_array_by_zero(rank, power);
	if (f->flags->lf)
		number.ld = va_arg(arg_ptr, long double);
	else
		number.ld = va_arg(arg_ptr, double);
	//get sign
	get_fraction(rank, number.part.fraction);
	exp = number.part.exponent - 16383 - 63;
	get(power, exp);
	mult(rank, power);
	

}
