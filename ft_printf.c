#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	int a = 0;
	int result = 0;
	int len = strlen(format); 
    va_list args;
    va_start(args, format);
	while(a < len)
	{
		if(format[a] == '%' && format[a+1] == 'i')
		{
			int x = va_arg(args, int);
			printf("%i", x);
		}
		a++;
	}
	va_end(args);

	return (a);
}

int main()
{
	int n = 10;
	ft_printf("%i %i", 10, 50);
}