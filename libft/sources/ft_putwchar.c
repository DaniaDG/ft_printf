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

int		ft_putwchar(wchar_t c)
{
	unsigned int i;
	char	t[4] = { 0 };

	i = 0;
	if (c < 0x80)
	{
		t[0] = (char) (c & 0x7f);
		i = 1;
	}
	else if (c < 0x800)
	{
		t[0] = (char) (((c >> 6) & 0x1f) | 0xc0);
		t[1] = (char) ((c & 0x3f) | 0x80);
		i = 2;
	}
	else if (c < 0x10000)
	{
		t[0] = (char) (((c >> 12) & 0xf) | 0xe0);
		t[1] = (char) (((c >> 6 & 0x3f)) | 0x80);
		t[2] = (char) ((c & 0x3f) | 0x80);
		i = 3;
	}
	else
	{
		t[0] = (char) (((c >> 18) & 0x7) | 0xf0);
		t[1] = (char) (((c >> 12) & 0x3f) | 0x80);
		t[2] = (char) (((c >> 6) & 0x3f) | 0x80);
		t[3] = (char) ((c & 0x3f) | 0x80);
		i = 4;
	}
	write(1, t, i);
	return (i);
	}
