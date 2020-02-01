/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	round_nine(char *str)
{
	if (*str != '9')
	{
		*str += 1;
		return ;
	}
	else
	{
		*str = '0';
		str--;
		round_nine(str);
	}
}

int		check_zeros(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != 0)
			return (1);
	}
	return (0);
}

void	ft_round(char *str_ptr, int sign)
{
	char	*str;

	str = str_ptr;
	if (*str >= '0' && *str < '5')
		*str = '\0';
	else if ((*str > '5' && *str <= '9') || (*str == '5' && check_zeros(str)))
	{
		*str = '\0';
		str--;
		round_nine(str);
	}
	else if (*str == '5')
	{
		*str = '\0';
		str--;
		if (*str & 1 && sign > 0)
			round_nine(str);
		if (!(*str & 1) && sign < 0)
			round_nine(str);
	}
}

void	rounding(char *str, int exp, t_f *f)
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

void	data_cpy(char *res, char *str, int exp, int fract_len)
{
	int		whole_len;
	int		i = 0;
	int		k = 0;

	i = 0;
	k = str[k] == '0' ? 1 : 0;
	if (exp >= 0)
		whole_len = ft_strlen(&str[k]);
	else
		whole_len = ft_strlen(&str[k]) - ft_min(fract_len, -exp);
	if (!whole_len)
		res[i++] = '0';
	while (whole_len)
	{
		res[i++] = str[k++];
		whole_len--;
	}
	res[i++] = '.';
	while (fract_len && str[k])
	{
		res[i++] = str[k++];
		fract_len--;
	}
	while (fract_len)
	{
		res[i++] = '0';
		fract_len--;
	}
	res[i] = 0;
}

void	put_dot(char *str, int exp, t_f *f)
{
	int		len;
	int		fract_len;

	len = *str == '0' ? ft_strlen(str + 1) : ft_strlen (str);
	if (!(fract_len = f->flags->precision) && !f->flags->sharp)
		f->number->digits = *str == '0' ? ft_strdup(str + 1) : ft_strdup(str);
	else
	{
		if (exp < 0)
		{
			if (fract_len <= -exp)
			{
				len += len == fract_len ? 1 : 0;
				f->number->digits = (char*)malloc(sizeof(char) * (len + 2));
			}
			else
			{
				f->number->digits = (char*)malloc(sizeof(char) * (len + fract_len + exp + 2));
			}
		}
		if (exp > 0)
		{
			f->number->digits = (char*)malloc(sizeof(char) * (len + fract_len + 2));
		}
		data_cpy(f->number->digits, str, exp, fract_len);
	}
	
}
