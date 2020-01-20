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

#include "ft_printf.h"


int		main()
{
	int		i = 0;
	float			f = 73.99125722752572579000;
	ULL		arr[MAX_RANK];
	
	while (i < MAX_RANK)
		arr[i++] = 0;
	get(arr, -10);
	while (arr[i] != (ULL)(-1))
		i--;
	i--;
	while (i)
		printf("%09llu", arr[i--]);
	//i =  ft_printf("%f", f);
	//printf("\n");
	//    	printf("%f", f);
	//printf("\n****************\n");

	// i = printf("%.20f", -99.999999);
	// printf("\ni = %d", i);

	//printf("\ns = %s", ft_itoa_base(123456, 10));

	return (0);
}
