/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:00:20 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/23 10:00:21 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	//unsigned char 		uch_pos_1 = 100;
	//unsigned short		ush_pos_1 = 3047;
	//unsigned int		ui_pos_1 = 878023;
	//unsigned long		ul_pos_1 = 22337203685477;
	//unsigned long long	ull_pos_1 = 22337203685477;
	//unsigned long long  ullmax = 9223372036854775807;
	//unsigned long  		ulmax = 9223372036854775807;
	int		i;
	long double			f = 999999999999999999999999999999999999999999999999.999;

	i = ft_printf("%f", f);
	printf("\ni = %d", i);

	printf("\n****************\n");

	i = printf("%Lf", f);
	printf("\ni = %d", i);

	//printf("\ns = %s", ft_itoa_base(123456, 10));
	//test();
	//ft_printf("%f\n", f);
	return (0);
}
