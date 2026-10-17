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
	//else if (type == 'p')
		//return (ft_printPtr(va_arg(args, void *)));

	/*
	else if (type == 'd')

	else if (type == 'i')

	else if (type == 'u')

	else if (type == 'x')

	else if (type == 'X')
	*/	
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
		else
			write(1, &c, 1);
		s++;
	}
	va_end(args);
	return (cntr);
}
