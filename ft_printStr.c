#include "ft_printf.h"

int	ft_printStr(char *s)
{
	int	cntr;
	char	c;

	cntr = 0;
	while (*s)
	{
		c = *s;
		write(1, &c, 1);
		cntr++;
		s++;
	}
	return (cntr);
}
/*
#include <stdio.h>
int main()
{
	int x = ft_printStr("akram sallam       \n");
	printf("%i\n", x);

	return 0;
}
*/
