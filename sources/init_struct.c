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
	f->res = 0;
	if (!(f->flags = (t_flags*)malloc(sizeof(t_flags))))
		exit(1);
	free_flags(f->flags);
	if (!(f->string = (t_string*)malloc(sizeof(t_string))))
		exit(1);
	f->string->left = NULL;
	f->string->str = NULL;
	f->string->right = NULL;
	if (!(f->number = (t_integer*)malloc(sizeof(t_integer))))
		exit(1);
	f->number->sign = 0;
	f->number->ox = NULL;
	f->number->left = NULL;
	f->number->right = NULL;
	f->number->digits = NULL;
	f->number->zeros = NULL;
	if (!(f->character = (t_character*)malloc(sizeof(t_character))))
		exit(1);
	f->character->left = NULL;
	f->character->c = 0;
	f->character->wc = 0;
	ft_memset(f->character->wc_str, 0, 4);
	f->character->right = NULL;
}
