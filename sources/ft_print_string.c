/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:34:18 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/27 13:34:19 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	print_and_free_string_struct(t_string *string)
{
	if (string->left)
		write(1, string->left, ft_strlen(string->left));
	if (string->str)
		write(1, string->str, ft_strlen(string->str));
	if (string->right)
		write(1, string->right, ft_strlen(string->right));
	ft_memdel((void**)&string->left);
	ft_memdel((void**)&string->str);
	ft_memdel((void**)&string->right);
}

int		ft_print_string(char *arg, t_flags *flags)
{
	int			len;
	t_string	string;

	string.left = NULL;
	string.str = NULL;
	string.right = NULL;
	if (flags->dot)
	{
		if (!flags->precision)
			len = 0;
		else
		{
			string.str = ft_strsub(arg, 0, ft_min(flags->precision, ft_strlen(arg)));
			len = ft_strlen(string.str);
		}
	}
	else
	{
		string.str = ft_strdup(arg);
		len = ft_strlen(string.str);
	}
	if (flags->minus)
		string.right = n_char(' ', flags->width - len, &len);
	else
		string.left = n_char(' ', flags->width - len, &len);
	print_and_free_string_struct(&string);
	free_flags(flags);
	return (len);
}
