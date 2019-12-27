/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:44:58 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 14:29:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	rem_letter(int rem)
{
	if (rem >= 10 && rem <= 15)
		return (rem + 55);
	else
		return (rem + '0');
}

int		num_of_letters(int value, int base)
{
	int i;

	i = 0;
	if (value < 0 && base == 10)
		i++;
	if (!value)
		return (1);
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
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
			if (base == 10)
				str[0] = '-';
			str[len--] = rem_letter((value % base) * (-1));
			value = (value / base) * (-1);
		}
		while (value != 0)
		{
			str[len--] = rem_letter((value % base));
			value = value / base;
		}
	}
	return (str);
}
