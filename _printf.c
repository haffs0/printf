#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>


/**
 * _strrev - string reversal function
 * @str: character
 * Return: char str
 */

char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}

	return (str);
}


/**
 * _itoa - converts to string
 * @i: integer
 * @strout: string output
 * @base: base 10
 * Return: strout.
 */


char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}

	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}

	if (sign)
	{
		*str++ = '-';
	}

	*str = '\0';
	_strrev(strout);

	return (strout);
}

/**
 * _printf - main function that produces output
 * @format: format character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	char tmp[20];
	char s[1000] = {0};
	va_list ap;
	char *str_arg;

	if (format == NULL)
		exit(98);

	va_start(ap, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				/* convert char */
				case 'c':
				{
					s[j] = (char) va_arg(ap, int);
					j++;
					break;
				}
				/* convert decimal */
				case 'd':
				{
					_itoa(va_arg(ap, int), tmp, 10);
					strcpy(&s[j], tmp);
					j += strlen(tmp);
					break;
				}
				/* convert percentage */
				case '%':
				{
					s[j] = format[i];
					j++;
					break;
				}
				/* convert string */
				case 's':
				{
					str_arg = va_arg(ap, char*);
					strcpy(&s[j], str_arg);
					j += strlen(str_arg);
					break;
				}
				/* convert integer */
				case 'i':
				{
					_itoa(va_arg(ap, int), tmp, 10);
					strcpy(&s[j], tmp);
					j += strlen(tmp);
					break;
				}
			}
		}
		else
		{
			s[j] = format[i];
			j++;
		}
		i++;
	}

	write(1, s, j);
	va_end(ap);

	return (j);
}
