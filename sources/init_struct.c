/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:32:15 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:32:17 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_f(t_f *f)
{
	f->flags = (t_flags*)malloc(sizeof(t_flags));
	free_flags(f->flags);
	f->string = (t_string*)malloc(sizeof(t_string));
	f->string->left = NULL;
	f->string->str = NULL;
	f->string->right = NULL;
	f->number = (t_integer*)malloc(sizeof(t_integer));
	f->number->sign = 0;
	f->number->ox = NULL;
	f->number->left = NULL;
	f->number->right = NULL;
	f->number->digits = NULL;
	f->number->zeros = NULL;
	f->character = (t_character*)malloc(sizeof(t_character));
	f->character->left = NULL;
	f->character->c = 0;
	f->character->right = NULL;
}
