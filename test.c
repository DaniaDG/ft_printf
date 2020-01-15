#include <stdio.h>

# define ARRAY {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}


int		main()
{
	int		i = 0;
	while (i < 10)
	{
		printf("%d", ARRAY[i]);
		i++;
	}
	return (0);
}
