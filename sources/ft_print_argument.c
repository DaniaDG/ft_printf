/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:33:45 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:33:47 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_argument(va_list arg_ptr, t_f *f)
{
	if (f->flags->conversion == 'd' || f->flags->conversion == 'i')
		return (di_case(arg_ptr, f));
	if (f->flags->conversion == 'u')
		return (u_case(arg_ptr, f));
	if (f->flags->conversion == 'x' || f->flags->conversion == 'X')
		return (x_case(arg_ptr, f));
	if (f->flags->conversion == 'o')
		return (o_case(arg_ptr, f));
	if (f->flags->conversion == 'p')
		return (p_case(arg_ptr, f));
	if (f->flags->conversion == 'f')
		return (f_case(arg_ptr, f));
	if (f->flags->conversion == 's')
		return (ft_print_string(arg_ptr, f));
	if (f->flags->conversion == 'c' || f->flags->conversion == '%')
		return (ft_print_char(arg_ptr, f));
	return (0);
}
