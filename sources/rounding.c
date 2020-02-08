/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:34:18 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:34:19 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		round_digit(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp == '9')
	{
		*tmp = '0';
		tmp--;
	}
	*tmp = *tmp + 1;
}

static int		check_zeros(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

static void		ft_round(char *str_ptr, int sign)
{
	char	*str;

	str = str_ptr;
	if (*str >= '0' && *str < '5')
		*str = '\0';
	else if ((*str > '5' && *str <= '9') || (*str == '5' && check_zeros(str + 1)))
	{
		*str = '\0';
		str--;
		round_digit(str);
	}
	else if (*str == '5')
	{
		*str = '\0';
		str--;
		if (*str & 1 && sign > 0)
			round_digit(str);
		if (!(*str & 1) && sign < 0)
			round_digit(str);
	}
}

void			rounding(char *str, int exp, t_f *f)
{
	int		len;
	int		sign;

	sign = f->number->sign == '-' ? -1 : 1;
	if (exp < 0)
	{
		exp *= -1;
		len = ft_strlen(str);
		if (len - 1 == exp)
			ft_round(str + f->flags->precision + 1, sign);
		if (len - 1 > exp)
			ft_round(str + len - exp + f->flags->precision, sign);
	}
}
