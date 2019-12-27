/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:00:26 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/23 10:00:27 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


typedef struct			s_flags
{
	int		zero;
	int		minus;
	int		plus;
	int		width;
	int		dot;
	int		precision;
	int		space;
}						t_flags;

typedef struct			s_integer
{
	char	*left;
	char	sign;
	char	*zeros;
	char	*digits;
	char	*right;
}						t_integer;



int		ft_printf(const char *format, ...);
int		ft_print_int(int arg, t_flags *flags);
void	ft_print_nchar(char c, int i);
int		ft_intlen(int n);
void	free_flags(t_flags *flags);
int		ft_print_string(char *arg, t_flags *flags);
char	*ft_itoa_base(int value, int base);

#endif
