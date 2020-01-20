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
	str = (char *)malloc(sizeof(char) * (n + 1));
	str[n--] = '\0';
	while (n >= 0)
		str[n--] = c;
	*len = *len + tmp;
	return (str);
}


int		go_to_format(t_f *f)
{
	int		len;

	len = 0;
	if (f->f_number->fract_part)
		len += ft_strlen(f->f_number->fract_part);
	if (len < f->flags->precision)
		f->f_number->zeros = n_char('0', f->flags->precision - len + 1, &len);
	if (f->f_number->whole_part)
		len += ft_strlen(f->f_number->whole_part);
	if (f->flags->precision)
	{
		len += f->f_number->sign ? 1 : 0;
		if (f->flags->minus)
			f->f_number->right = n_char(' ', f->flags->width - len, &len);
		else if (f->flags->zero)
			f->f_number->left = n_char('0', f->flags->width - len, &len);
		else
			f->f_number->left = n_char(' ', f->flags->width - len, &len);
	}
	/*else
	{
		len += f->f_number->sign ? 1 : 0;
		if (f->flags->zero)
			f->f_number->right = n_char('0', f->flags->width - len, &len);
		else
			f->f_number->left = n_char(' ', f->flags->width - len, &len);
	}*/
	return (len);
}
