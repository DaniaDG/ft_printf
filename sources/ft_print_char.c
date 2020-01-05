/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:23:41 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/03 13:23:42 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_and_free_char_struct(t_character *character)
{
	if (character->left)
		write(1, character->left, ft_strlen(character->left));
	write(1, &(character->c), 1);
	if (character->right)
		write(1, character->right, ft_strlen(character->right));
	ft_memdel((void**)&character->left);
	ft_memdel((void**)&character->right);
	character->c = 0;
}

int		ft_print_char(va_list arg_ptr, t_f *f)
{
	int				len;

	len = 1;
	if (f->flags->percent)
		f->character->c = '%';
	else
		f->character->c = (char)va_arg(arg_ptr, int);
	if (f->flags->minus)
		f->character->right = n_char(' ', f->flags->width - 1, &len);
	else
		f->character->left = n_char(' ', f->flags->width - 1, &len);
	print_and_free_char_struct(f->character);
	free_flags(f->flags);
	return (len);
}

void	get_adress(va_list arg_ptr, t_f *f)
{
	unsigned long long adress;

	adress = (unsigned long long)va_arg(arg_ptr, void*);
	if (!adress && f->flags->dot)
		f->number->digits = ft_strdup("\0");
	else
		f->number->digits = ft_itoa_base_unsigned(adress, 16, 0);
}

int		ft_print_adress(va_list arg_ptr, t_f *f)
{
	int		len;

	get_adress(arg_ptr, f);
	len = ft_strlen(f->number->digits);
	if (f->flags->dot)
		precision_case(f, &len);
	else
		only_width_case(f, &len);
	print_and_free_int_struct(f->number);
	free_flags(f->flags);
	return (len);
}
