#include <stdio.h>
#include <stdarg.h>
#include "include/ft_printf.h"

int		main(void)
{
	printf("sortie: |%d|\n", printf("ouesh negro|%zXtest string: |%s|\n", 13122343441234, "ceci est un test a;sdflkj \a"));
	printf("sortie: |%d|\n", ft_printf("ouesh negro|%zXtest string: |%s|\n", 13122343441234, "ceci est un test a;sdflkj \a"));
	
	return (0);
}