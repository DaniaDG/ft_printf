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
	unsigned char 		uch_pos_1 = 100;
	unsigned short		ush_pos_1 = 3047;
	unsigned int		ui_pos_1 = 878023;
	unsigned long		ul_pos_1 = 22337203685477;
	unsigned long long	ull_pos_1 = 22337203685477;
	unsigned long long  ullmax = 9223372036854775807;
	unsigned long  		ulmax = 9223372036854775807;
	int		i = 0;
	int		n = sizeof(long double);
	union union_type	tmp;
	double			f = 0.3333333333;
	//unsigned long long	a = 1;

	//a = a << 52;
	tmp.ld = (long double)4.123;

	printf("%d\n", n);
	while (i < 64)
		printf("%u", tmp.bit[i++]);
	//printf("sign = %s\n", ft_itoa_base_unsigned(tmp.ld_part.sign, 2, 0));
	//printf("exponent = %s\n", ft_itoa_base_unsigned(tmp.ld_part.exponent, 2, 0));
	//printf("fraction = %s\n", ft_itoa_base_unsigned(tmp.ld_part.fraction, 2, 0));


	//printf("sign = %x\n", tmp.ld_part.sign);
	//printf("exponent = %x\n", tmp.ld_part.exponent);
	//printf("fraction = %llx\n", tmp.ld_part.fraction);
	//printf("number = %Lf\n", tmp.ld);
	/*i = ft_printf("%010s", "123");
	printf("\ni = %d", i);

	printf("\n****************\n");

	i = printf("%010s", "123");
	printf("\ni = %d", i);*/

	//printf("\ns = %s", ft_itoa_base(123456, 10));
	return (0);
}
