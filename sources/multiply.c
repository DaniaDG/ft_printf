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

/*void	mult(ULL *m1, ULL *m2)
{
	int		i;
	int		k;
	ULL		tmp[MAX_RANK];

	i = 0;
	while (i < MAX_RANK)
		tmp[i++] = 0;
	k = 1;
	while (k < MAX_RANK)
	{
		i = 1;
		while (i + k - 1 < MAX_RANK)
		{
			tmp[i + k - 1] += m1[i] * m2[k];
			tmp[i + k - 1] += tmp[i + k - 2] / 1000000000;
			tmp[i + k - 2] %= 1000000000;
			i++;
		}
		k++;
	}
	i = 0;
	while (++i < MAX_RANK)
		m1[i] = tmp[i];
}*/

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

void	ft_round(char *str_ptr)
{
	char	*str;
	str = str_ptr;
	if (*str >= '0' && *str < '5')
		*str = '\0';
	if (*str >= '5' && *str <= '9')
	{
		*str = '\0';
		str--;
		round_nine(str);
	}
}

void	rounding(char *str, int exp, t_f *f)
{
	int		len;

	if (exp < 0)
	{
		exp *= -1;
		len = ft_strlen(str);
		if (len - 1 == exp)
			ft_round(str + f->flags->precision + 1);
		if (len - 1 > exp)
			ft_round(str + len - exp + f->flags->precision);
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
	char	*res;

	len = *str == '0' ? ft_strlen(str + 1) : ft_strlen (str);
	fract_len = f->flags->precision;
	if (exp < 0 && fract_len)
	{
		//exp *= -1;
		if (fract_len <= -exp)
		{
			len += len == fract_len ? 1 : 0;
			res = (char*)malloc(sizeof(char) * (len + 2));
			//res[len + 1] = 0;
		}
		else
		{
			res = (char*)malloc(sizeof(char) * (len + fract_len + exp + 2));
			//res[len + fract_len + exp + 1] = 0;
		}
	}
	if (exp > 0 && fract_len)
	{
		res = (char*)malloc(sizeof(char) * (len + fract_len + 2));
		//res[len + fract_len + 1] = 0;
	}
	data_cpy(res, str, exp, fract_len);
	printf("RES = %s\n", res);
}
