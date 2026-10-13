#include "ft_printf.h"

static int	printType(va_list args, char type)
{
	char	c;

	if (type == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (type == 's')
		return (ft_printStr(va_arg(args, char *)));
		
	return 1;
}

int	ft_printf(const char *s, ...)
{
	va_list args;
	int	cntr;
	char	c;

	va_start(args, s);
	cntr = 0;
	while (*s)
	{
		c = *s;
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				cntr += write(1, "%", 1);
			else 
				cntr += printType(args, *s);
		}
		write(1, &c, 1);
		s++;
	}
	va_end(args);
	return (cntr);
}
