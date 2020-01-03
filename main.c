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
	int		i;

	i = ft_printf("@moulitest: %s %s %s %s", NULL, "bla", "123", "5");
	printf("\ni = %d", i);

	printf("\n********55******\n");

	i = printf("@moulitest: %s", NULL);
	printf("\ni = %d", i);

	//printf("\ns = %s", ft_itoa_base(123456, 10));
	return (0);
}
