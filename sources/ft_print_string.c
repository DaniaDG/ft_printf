/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:34:18 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:34:19 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_print_string(char *arg, t_flags *flags)
{
	int		len;
	int		n;

	len = ft_strlen(arg);
	if (!flags->minus)
		ft_print_nchar(' ', flags->width - len);
	write(1, arg, len);
	if (flags->minus)
		ft_print_nchar(' ', flags->width - len);
	n = flags->width - len <= 0 ? 0 : flags->width - len;
	return (len + n);
}
