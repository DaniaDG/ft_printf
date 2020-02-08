#include <stdio.h>
#include <unistd.h>


int		main()
{
	int		a;
	int		b;

	a = 3;
	b = 5;

	if ((b > 0) && (a = 1))
		b = 10;
	printf("%d\n", b);
	printf("%d\n", a);
	return (0);
}
