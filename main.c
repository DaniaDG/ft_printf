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
	int		i = 8;
	union union_type	tmp;
	t_fp_format			fp;
	double			f = 4.123;

	tmp.ld = f;
	while (i-- > 0)
		printf("%x ", tmp.bit[i]);
	fp.sign = tmp.bit[7] >> 7;
	printf("\nsign = %d\n", fp.sign);
	fp.exponent = tmp.bit[7] << 4 | tmp.bit[6] >> 4;
	printf("exponent = %x   (%u)\n", fp.exponent, fp.exponent);
	fp.fraction = (tmp.bit[6] & 0x0F) * pow(256, 6) + tmp.bit[5] * pow(256, 5) +
					tmp.bit[4] * pow(256, 4) + tmp.bit[3] * pow(256, 3) +
					tmp.bit[2] * pow(256, 2) + tmp.bit[1] * pow(256, 1) + tmp.bit[0];
	printf("fraction = %llx   (%llu)\n", fp.fraction, fp.fraction);

	/*printf("sign = %s\n", ft_itoa_base_unsigned(tmp.sign, 2, 0));
	printf("exponent = %s\n", ft_itoa_base_unsigned(tmp.exponent, 2, 0));
	printf("fraction = %s\n", ft_itoa_base_unsigned(tmp.fraction, 2, 0));


	printf("sign = %d\n", tmp.sign);
	printf("exponent = %d\n", tmp.exponent);
	printf("fraction = %lld\n", tmp.fraction);*/
	printf("\nnumber = %f\n", tmp.ld);
	/*i = ft_printf("%010s", "123");
	printf("\ni = %d", i);

	printf("\n****************\n");

	i = printf("%010s", "123");
	printf("\ni = %d", i);*/

	//printf("\ns = %s", ft_itoa_base(123456, 10));
	return (0);
}
