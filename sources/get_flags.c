/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(char *ptr, t_flags *flags)
{
	int		i = 0;

	if (!ptr[i])
		return (0);
	if (ft_strchr("%cspdiouxX", ptr[i]))
	{
		if (ptr[i] == '%')
			flags->percent = 1;
		return (1);
	}
	while (ptr[i] && ft_strchr("hl0123456789 .+-#", ptr[i]))///check while ptr[i+1]
	{
		if (ptr[i] == '0')
			flags->zero = 1;
		if (ptr[i] == '-')
			flags->minus = 1;
		if (ptr[i] == '+')
			flags->plus = 1;
		if (ptr[i] == ' ')
			flags->space = 1;
		if (ptr[i] == '.')
			flags->dot = 1;
		if (ptr[i] == '#')
			flags->sharp = 1;
		if (ptr[i] >= '1' && ptr[i] <= '9')
		{
			if (flags->dot)
				flags->precision = ft_atoi(&ptr[i]);
			else
				flags->width = ft_atoi(&ptr[i]);
			while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')///check while ptr[i+1]
				i++;
			i--;
		}
		if (ptr[i] == 'h')
		{
			flags->h = 1;
			if (ptr[i - 1] == 'h')
			{
				flags->hh = 1;
				flags->h = 0;
			}
		}
		if (ptr[i] == 'l')
		{
			flags->l = 1;
			if (ptr[i - 1] == 'l')
			{
				flags->ll = 1;
				flags->l = 0;
			}
		}
		i++;
		if (ptr[i] == '%')
		{
			flags->percent = 1;
			break ;
		}
	}
	return (i + 1);
}
