/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_nan_inf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_infinity(t_ext_format number)
{
	unsigned long long	fraction;
	int					i;

	if (number.part.exponent != 0x7FFF)
		return (0);
	fraction = number.part.fraction;
	i = 0;
	while (!(fraction & 1))
	{
		i++;
		fraction = fraction >> 1;
	}
	if (i == 63)
		return (1);
	return (0);
}

int			check_special_numbers(t_ext_format number, t_f *f)
{
	if (number.ld == 0)
	{
		if (f->flags->precision)
		{
			f->number->digits = n_char('0', f->flags->precision + 2, NULL);
			f->number->digits[1] = '.';
		}
		else if (f->flags->sharp)
			f->number->digits = ft_strdup("0.");
		else
			f->number->digits = ft_strdup("0");
	}
	else if (number.ld != number.ld)
	{
		f->number->digits = ft_strdup("nan");
		f->number->sign = 0;
	}
	else if (check_infinity(number))
		f->number->digits = ft_strdup(f->flags->conversion == 'f' ?
													"inf" : "INF");
	else
		return (0);
	return (1);
}
