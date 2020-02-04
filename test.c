#include <stdio.h>
#include <unistd.h>


int		main()
{
	write(1, "\033[7mHI\n", 8);
	return (0);
}
