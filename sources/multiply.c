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

void	mult(ULL *m1, ULL *m2)
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
}

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

void	rounding(char *str_ptr)
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

/*void	test()
{
	ULL	m1[MAX_RANK];
	ULL	m2[MAX_RANK];
	int		i = -1;
	unsigned long long a = 123456789123456789;
	unsigned long long b = 23652365236523;

	while (++i < MAX_RANK)
	{
		m1[i] = 0;
		m2[i] = 0;
	}
	i = 1;
	while (a)
	{
		m1[i++] = a % 1000000000;
		a = a / 1000000000;
	}
	i = 1;
	while (b)
	{
		m2[i++] = b % 1000000000;
		b = b / 1000000000;
	}
	mult(m1, m2);
	i = 10;
	while (i > 0)
		ft_printf("04ld", m1[i]);
}
*/
