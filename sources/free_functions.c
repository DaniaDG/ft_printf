/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:36:49 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:36:50 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->percent = 0;
	flags->size = 0;
	flags->conversion = 0;
}

void	free_int_struct(t_integer *number)
{
	ft_memdel((void**)&(number->left));
	ft_memdel((void**)&(number->ox));
	ft_memdel((void**)&(number->zeros));
	ft_memdel((void**)&(number->digits));
	ft_memdel((void**)&(number->right));
	number->sign = 0;
}

void	free_string_srtuct(t_string *string)
{
	ft_memdel((void**)&(string->left));
	ft_memdel((void**)&(string->str));
	ft_memdel((void**)&(string->right));
}

void	free_char_srtuct(t_character *character)
{
	ft_memdel((void**)&character->left);
	ft_memdel((void**)&character->right);
	character->c = 0;
	character->wc = 0;
	ft_memset(character->wc_str, 0, 4);
}

void	free_all(t_f *f)
{
	ft_memdel((void**)&(f->flags));
	ft_memdel((void**)&(f->number));
	ft_memdel((void**)&(f->string));
	ft_memdel((void**)&(f->character));
}
