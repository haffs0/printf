#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


/**
 *
 *
 *
 */

int vprintf(const char *format, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);

	printf("f1: %s, f2: %s\n ", format, s);
	return (0);
}

/**
 *
 *
 *
 */

int _printf(const char *format, ...)
{
	int i;
	char *s;
	va_list argStr;

	if (format == NULL) exit(98);

	s = malloc((sizeof(char) * (int) strlen(format)) + 1);

	if (s == NULL) return (0);

	va_start(argStr, format);

	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) != '[')
			s[i] = *(format + i);
		else
		{
			s[i] = vprintf((const) *(format + i + 2), argStr);
			i += 3;
		}
	}

	va_end(argStr);

	return (0);
}
