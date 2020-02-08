/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_digit_str(unsigned long long *rank)
{
	int		k;
	int		len;

	len = 0;
	k = 1;
	while (rank[rank[0]] / k)
	{
		len++;
		k *= 10;
	}
	len += (rank[0] - 1) * 9;
	return (len);
}

static void		fill_str(char *tmp_str, unsigned long long *rank)
{
	int		k;
	int		i;

	k = 100000000;
	i = rank[0];
	if (rank[i] / 100000000 == 0)
	{
		while (k && rank[i] / k == 0)
			k = k / 10;
	}
	while (i > 0)
	{
		if (i != (int)rank[0])
			k = 100000000;
		while (k)
		{
			*tmp_str = rank[i] / k + '0';
			rank[i] %= k;
			tmp_str++;
			k /= 10;
		}
		i--;
	}
	*tmp_str = 0;
}

char			*convert_to_str(unsigned long long *rank, int exp)
{
	char	*str;
	char	*tmp_str;
	int		len;
	int		len_fract;

	len = len_digit_str(rank);
	len_fract = exp < 0 ? -exp : 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_max(len, len_fract) + 2))))
		return (NULL);
	tmp_str = str;
	*tmp_str = '0';
	tmp_str++;
	if (exp < 0 && -exp - len > 0)
	{
		exp = -exp - len;
		while (exp)
		{
			*tmp_str = '0';
			exp--;
			tmp_str++;
		}
	}
	fill_str(tmp_str, rank);
	return (str);
}
