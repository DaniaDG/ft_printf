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


int		multiply()
{
	//long double			tmp;
	unsigned long long	tmp;
	union union_type	number;
	int					rank[1000];
	int					i = 0;
	int					exp = -1;

	while (i < 1000)
	{
		rank[i] = 0;
		i++;
	}
	number.ld = 0.875;
	printf("sign = %x\n", number.part.sign);
	printf("exponent = %x   (%u)\n", number.part.exponent, number.part.exponent);
	printf("fraction = %llx   (%llu)\n", number.part.fraction, number.part.fraction);
	printf("number = %Lf\n", number.ld);
	tmp = number.part.fraction;
	i = 0;
	while (tmp)
	{
		rank[i++] = tmp % 100000;
		tmp = tmp / 100000;
	}
	i = 0;
	while (i < 10)
		printf("%d\n", rank[i++]);
	printf("****************************\n");
	if (exp > 0)
	{
		while (exp)
		{
			i = 0;
			while (rank[i])
			{
				rank[i] *= 2;
				if (i > 0 && rank[i - 1] > 99999)
				{
					rank[i]++;
					rank[i - 1] = rank[i - 1] % 100000;
				}
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
			i = 0;
			rank[i++] *= 5;
			while (rank[i])
			{
				rank[i] *= 5;
				rank[i] += rank[i - 1] / 100000;
				rank[i - 1] = rank[i - 1] % 100000;
				i++;
			}
			rank[i] += rank[i - 1] / 100000;
			rank[i - 1] = rank[i - 1] % 100000;
			exp--;
		}
	}
	i = 0;
	while (i < 15)
		printf("%d\n", rank[i++]);
	return (0);
}
