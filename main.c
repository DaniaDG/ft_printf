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
	int		i = 10;
	union union_type	tmp;
	t_fp_format			fp;
	long double			f = 4.123;

	/*tmp.ld = f;
	while (i-- > 0)
		printf("%x ", tmp.bit[i]);
	fp.sign = tmp.bit[9] >> 7;
	printf("\nsign = %d\n", fp.sign);
	fp.exponent = (tmp.bit[9] & 0x7F) << 8 | tmp.bit[8];
	printf("exponent = %x   (%u)\n", fp.exponent, fp.exponent);
	//fp.fraction = (tmp.bit[6] & 0x0F) * pow(256, 6) + tmp.bit[5] * pow(256, 5) +
	//				tmp.bit[4] * pow(256, 4) + tmp.bit[3] * pow(256, 3) +
	//				tmp.bit[2] * pow(256, 2) + tmp.bit[1] * pow(256, 1) + tmp.bit[0];
	//printf("fraction = %llx   (%llu)\n", fp.fraction, fp.fraction);

	printf("sign = %s\n", ft_itoa_base_unsigned(tmp.sign, 2, 0));
	printf("exponent = %s\n", ft_itoa_base_unsigned(tmp.exponent, 2, 0));
	printf("fraction = %s\n", ft_itoa_base_unsigned(tmp.fraction, 2, 0));*/
	multiply();
	//printf("sign = %x\n", tmp.part.sign);
	//printf("exponent = %x   (%u)\n", tmp.part.exponent, tmp.part.exponent);
	//printf("fraction = %llx   (%llu)\n", tmp.part.fraction, tmp.part.fraction);
	//printf("\nnumber = %Lf\n", tmp.ld);
	//printf("str number = %s\n", ft_itoa_base_unsigned(tmp.part.fraction, 10, 0));
	//i = ft_printf("%d", 123);
	//printf("\ni = %d", i);

	//printf("\n****************\n");

	//i = printf("%d", 123);
	//printf("\ni = %d", i);

	//printf("\ns = %s", ft_itoa_base(123456, 10));
	return (0);
}
