#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    char c = 'A';
    char *str = "Hello, world!";
    void *ptr = &c;
    int d = -123;
    int i = 456;
    unsigned int u = 789;
    int hex = 255;

    ft_printf("Character: %c\n", c);
    ft_printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Decimal (%%d): %d\n", d);
    ft_printf("Integer (%%i): %i\n", i);
    ft_printf("Unsigned: %u\n", u);
    ft_printf("Hex lowercase: %x\n", hex);
    ft_printf("Hex uppercase: %X\n", hex);
    ft_printf("Percent sign: %%\n");
}