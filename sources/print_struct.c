/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:44:54 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:44:55 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_and_free_int_struct(t_integer *number)
{
	if (number->left)
		write(1, number->left, ft_strlen(number->left));
	if (number->sign)
		write(1, &(number->sign), 1);
	if (number->ox)
		write(1, number->ox, ft_strlen(number->ox));
	if (number->zeros)
		write(1, number->zeros, ft_strlen(number->zeros));
	if (number->digits)
		write(1, number->digits, ft_strlen(number->digits));
	if (number->right)
		write(1, number->right, ft_strlen(number->right));
	free_int_struct(number);
}

void	print_and_free_float_struct(t_float *number)
{
	if (number->left)
		write(1, number->left, ft_strlen(number->left));
	if (number->sign)
		write(1, &(number->sign), 1);
	if (number->whole_part)
		write(1, number->whole_part, ft_strlen(number->whole_part));
	if (number->fract_part)
		write(1, number->fract_part, ft_strlen(number->fract_part));
	if (number->zeros)
		write(1, number->zeros, ft_strlen(number->zeros));
	if (number->right)
		write(1, number->right, ft_strlen(number->right));
	free_float_struct(number);
}

void	print_and_free_string_struct(t_string *string)
{
	if (string->left)
		write(1, string->left, ft_strlen(string->left));
	if (string->str)
		write(1, string->str, ft_strlen(string->str));
	if (string->right)
		write(1, string->right, ft_strlen(string->right));
	free_string_srtuct(string);
}

void	print_and_free_char_struct(t_f *f, int *len)
{
	if (f->character->left)
		write(1, f->character->left, ft_strlen(f->character->left));
	if (f->flags->size == L)
		*len += ft_putwchar(f->character->wc) - 1;
	else
		write(1, &(f->character->c), 1);
	if (f->character->right)
		write(1, f->character->right, ft_strlen(f->character->right));
	free_char_srtuct(f->character);
}
