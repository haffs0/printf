#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2;

    _printf("%c %d %s\n", 'A', 10, "haffs boy");
    len = _printf(".\n");
    len2 = printf("My solution used eight helper functions in addition to the myprintf() function. I suggest you first implement and test this program using C. Write drivers which will test the helper functions. Now, one at a time, create an equivalent SPARC routine for each C function. Start with a simple leaf function (such as the one which multiplies by 10). Link it with your working program so that everything is in C except for this low-level function. Test it carefully. Continue by translating and testing each function until at last myprintf() is complete.\n");
    len2 = printf("My solution used eight helper functions in addition to the myprintf() function. I suggest you first implement and test this program using C. Write drivers which will test the helper functions. Now, one at a time, create an equivalent SPARC routine for each C function. Start with a simple leaf function (such as the one which multiplies by 10). Link it with your working program so that everything is in C except for this low-level function. Test it carefully. Continue by translating and testing each function until at last myprintf() is complete..\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
}
