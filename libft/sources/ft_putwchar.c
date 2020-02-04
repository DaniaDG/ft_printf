/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:35:26 by bsausage          #+#    #+#             */
/*   Updated: 2019/09/06 18:36:07 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	/*unsigned int i;
	char	t[4] = { 0 };

	i = 0;
	if (c < 0x8000)
	{
		t[0] = (char) ((c >> 6) | 0xc0);
		t[1] = (char) ((c & 0x3f) | 0x80);
		i = 2;
	}
	else if (c < 0x80000)
	{
		t[0] = (char) ((c >> 12) | 0xc0);
		t[1] = (char) (((c >> 6 & 0x3f)) | 0x80);
		t[2] = (char) ((c & 0x3f) | 0x80);
		i = 3;
	}
	else
	{
		t[0] = (char) ((c >> 18) | 0xc0);
		t[1] = (char) (((c >> 12) & 0x3f) | 0x80);
		t[2] = (char) (((c >> 6) & 0x3f) | 0x80);
		t[3] = (char) ((c & 0x3f) | 0x80);
		i = 4;
	}
	write(1, t, i);*/


	t_unicode		character;
	char			tmp[4];
	int				i;

	i = 0;
	character.c = c;
	
	while (i < 4)
	{
		tmp[3 - i] = character.part[i];
		i++;
	}
	write(1, tmp, 4);
}
