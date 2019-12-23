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
	int		a = 5;
	int		b = 0;
	char	c = 'A';


	ft_printf("%+d %d \t%d \\%s %c %%", a, b, 125, "Hello my friend", c);
	printf("\n\n");
	   printf("%+d %d \t%d \\%s %c %%", a, b, 125, "Hello my friend", c);
	
	printf("\n\n");
	printf("%123d", 12);
	return (0);
}
