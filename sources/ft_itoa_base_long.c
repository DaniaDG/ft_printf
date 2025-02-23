/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:44:58 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 14:29:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		rem_letter(int rem, int reg)
{
	if (rem >= 10 && rem <= 15)
	{
		if (reg)
			return (rem + 55);
		return (rem + 87);
	}
	return (rem + '0');
}

static int		num_of_letters(long long value, int base)
{
	int i;

	i = 0;
	if (!value)
		return (1);
	while (value != 0)
	{
		value = (long long)(value / (long long)base);
		i++;
	}
	return (i);
}

char			*ft_itoa_base_long(long long value, int base, int reg)
{
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (0);
	len = num_of_letters(value, base);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len--] = '\0';
		if (!value)
			str[0] = '0';
		if (value < 0)
		{
			str[len--] = rem_letter((value % base) * (-1), reg);
			value = ((long long)(value / (long long)base)) * (-1);
		}
		while (value != 0)
		{
			str[len--] = rem_letter((value % base), reg);
			value = (long long)(value / (long long)base);
		}
	}
	return (str);
}
