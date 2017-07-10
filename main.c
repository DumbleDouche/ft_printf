#include <stdio.h>
#include <stdarg.h>
#include "include/ft_printf.h"

// void foo(char *fmt, ...)
// {
//     va_list ap;
//     int d;
//     char c, *s;

//     va_start(ap, fmt);
//     while (*fmt)
//         switch (*fmt ++) {
//         case aqsaq:              /* chaîne */
//             s = va_arg (ap, char *);
//             printf("chaîne %s\n", s);
//             break;
//         case aqdaq:              /* entier */
//             d = va_arg (ap, int);
//             printf("int %d\n", d);
//             break;
//         case aqcaq:              /* caractère */
//             /* need a cast here since va_arg only
//                takes fully promoted types */
//             c = va_arg (ap, char);
//             printf("char %c\n", c);
//             break;
//         }
//     va_end(ap);
// }

int		main(void)
{
	ft_printf("%douio odiu %d ah bon ? %d c'est vrai %d \n", 431, 654357, 1234, 14123);
	
	return (0);
}