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
	//int		a = 5;
	//int		b = 0;
	//char	c = 'A';
	unsigned int	b = 123;
	int		i;

	i = ft_printf("%hd", 50000);
	printf("\ni = %d", i);

	printf("\n****************\n");

	i = printf("%x", (unsigned int)-123);
	printf("\ni = %d", i);

	//printf("\ns = %s", ft_itoa_base(123456, 10));
	return (0);
}
