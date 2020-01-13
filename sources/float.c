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

/*void	round(char *str, int i)
{
	if (i >= ft_strlen(str))
		return ;
	if (str[i] > 5)
	{
		if (str[i - 1] != '9')
			str[i - 1]++;
		else
			str[i - 1] = '0';	
	}
}*/


int		multiply(va_list arg_ptr)
{
	unsigned long long	tmp;
	union union_type	number;
	long				rank[50];

	//double				d = 0;
	long double			ld = va_arg(arg_ptr, long double);
	//float				f = 0;

	int i = 0;
	while (i < 50)
	{
		rank[i] = 0;
		i++;
	}
	number.ld = ld;

	//printf("sign = %x\n", number.part.sign);
	printf("exponent = %x   (%u)\n", number.part.exponent, number.part.exponent);
	printf("fraction = %llx   (%llu)\n", number.part.fraction, number.part.fraction);
	//printf("number = %.80Lf\n", number.ld);
	//printf("%zu\n", ft_strlen("123456789012345677877719597056"));
	tmp = number.part.fraction;
	i = 0;
	while (tmp)
	{
		rank[i++] = tmp % 100000000;
		tmp = tmp / 100000000;
	}
	
	//i = 0;
	//while (i < 10)
	//	printf("%ld\n", rank[i++]);
	//printf("****************************\n");
	int exp = number.part.exponent - 16383 - 63;
	int dot = ld_len(ld);
	
	printf("exponent = %d\n", exp);
	printf("dot = %d\n", dot);

	if (exp > 0)
	{
		while (exp)
		{
			i = 0;
			rank[i++] *= 2;
			while (i < 25)
			{
				rank[i] *= 2;
				rank[i] += rank[i - 1] / 100000000;
				rank[i - 1] = rank[i - 1] % 100000000;
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
			while (i < 25)
			{
				rank[i] *= 5;
				rank[i] += rank[i - 1] / 100000000;
				rank[i - 1] = rank[i - 1] % 100000000;
				i++;
			}
			exp--;
		}
	}
	int len = 0;
	while (!rank[i])
		i--;
	int k = 1;
	while (rank[i] / k)
	{
		len++;
		k *= 10;
	}
	len += i * 8;
	printf("len = %d\n", len);
	char	*str;
	char	*tmp_str;
	str = (char *)malloc(sizeof(char) * (len + 1));
	tmp_str = str;
	str[len] = 0;
	k = 10000000;
	while (rank[i] / k == 0)
		k /= 10;
	if (!k)
		i--;
	while (i >= 0)
	{
		if (!k)
			k = 10000000;
		while (k)
		{
			*str = rank[i] / k + '0';
			rank[i] %= k;
			str++;
			k /= 10;
		}
		i--;
	}
	//
		//printf("%s", tmp_str);
		write(1, tmp_str, ft_strlen(tmp_str));
		printf("\n");
	exp = number.part.exponent - 16383 - 63;
	if (exp < 0)
	{
		i = ft_strlen(tmp_str) + exp;
		//round(tmp_str, i + 6);
		write(1, tmp_str, i);
		write(1, ".", 1);
		write(1, &tmp_str[i], ft_strlen(&tmp_str[i]));
	}
	else
	{
		i = ft_strlen(tmp_str) - exp;
		write(1, tmp_str, i);
		write(1, ".", 1);
		write(1, &tmp_str[i], ft_strlen(&tmp_str[i]));
	}
	return (0);
}
