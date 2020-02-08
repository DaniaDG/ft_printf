/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:59:16 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/23 10:59:17 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*n_char(char c, int n, int *len)
{
	char	*str;
	int		tmp;

	if (n <= 0)
		return (NULL);
	tmp = n;
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	str[n--] = '\0';
	while (n >= 0)
		str[n--] = c;
	if (len)
		*len = *len + tmp;
	return (str);
}

void	fill_array_by_zero(unsigned long long *array)
{
	int		i;

	i = 0;
	while (i < MAX_RANK)
	{
		array[i] = 0;
		i++;
	}
}
