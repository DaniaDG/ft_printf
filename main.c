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
#include <limits.h>
#include <float.h>
#include "libft.h"
#include <locale.h>

#include "ft_printf.h"

int		main()
{
	int		n;
	// ft_printf("%Lf\n", LDBL_MAX);
	 // printf("%.Lf\n", LDBL_MAX);

	//c = 0x1101;
	//t[0] = (char)(((c >> 6) & 0x1f) | 0xc0);
	//t[1] = (char)((c & 0x3f) | 0x80);

	//printf("%lu\n", sizeof(c));
	//setlocale(LC_CTYPE, "");
	////printf("%2lc\\n", L'Й');

	ft_printf("%.1f\n", 9.25);
	//printf("blablabla%n%-070.10f\n", NULL, 1.123456);
	//printf("%-070.10f\n", 1.123456);
	//ft_printf("%lc\\n", 'й');
	//write(1, t, sizeof(t));
	//printf("%d\n", printf("%5lc\n", c));
  /*ft_printf("\\n");
  ft_printf("%%\\n");
  ft_printf("%d\\n", 42);
  ft_printf("%d%d\\n", 42, 41);
  ft_printf("%d%d%d\\n", 42, 43, 44);
  ft_printf("%ld\\n", 2147483647);
  ft_printf("%lld\\n", 9223372036854775807);
  ft_printf("%x\\n", 505);
  ft_printf("%X\\n", 505);
  ft_printf("%p\\n", &ft_printf);
  ft_printf("%20.15d\\n", 54321);
  ft_printf("%-10d\\n", 3);
  ft_printf("% d\\n", 3);
  ft_printf("%+d\\n", 3);
  ft_printf("%010d\\n", 1);
  ft_printf("%hhd\\n", 0);
  ft_printf("%jd\\n", 9223372036854775807);
  ft_printf("%zd\\n", 4294967295);
  ft_printf("%\\n");
  ft_printf("%U\\n", 4294967295);
  ft_printf("%u\\n", 4294967295);
  ft_printf("%o\\n", 40);
  ft_printf("%%#08x\\n", 42);
  ft_printf("%x\\n", 1000);
  ft_printf("%#X\\n", 1000);
  ft_printf("%s\\n", NULL);
  //ft_printf("%S\\n", L"ݗݜशব");
  ft_printf("%s%s\\n", "test", "test");
  ft_printf("%s%s%s\\n", "test", "test", "test");
  ft_printf("%f", 0.0);
  ft_printf("%f", 0.0 / 0.0);
  ft_printf("%f", INFINITY);
  ft_printf("%.25Lf", 1.546846465465465465465453l);
  ft_printf("%15lf", 1.4546543);
  //ft_printf("%lc\\n", 15000);
 // while (1);*/
  return (0);
}

