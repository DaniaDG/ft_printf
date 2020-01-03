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
}

int		ft_print_char(char ch, t_flags *flags)
{
	t_character		character;
	int				len;

	character.left = NULL;
	character.c = ch;
	character.right = NULL;
	len = 1;
	if (flags->minus)
		character.right = n_char(' ', flags->width - 1, &len);
	else
		character.left = n_char(' ', flags->width - 1, &len);
	print_and_free_char_struct(&character);
	free_flags(flags);
	return (len);
}
