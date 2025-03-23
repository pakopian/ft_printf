/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <akopyanpyotrx99@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:57:18 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/23 17:22:36 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}
int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (*str)
{
		len++;
        str++;
}
    return (len);
}
static void check_modifier(char c, int *result, va_list args)
{
    if (c == '%')
        *result = ft_putchar('%');
    else if (c == 'c')
        *result += ft_putchar(va_arg(args, int));
    else if (c == 's')
        *result += print_string(va_arg(args, char *));
    else if (c == 'p')
        *result += print_pointer(va_arg(args, size_t));
    else if (c == 'i' || c == 'd')
        *result += print_int(va_arg(args, int));
    else if (c == 'u')
        *result += print_unsigned(va_arg(args, unsigned int));
    else if (c == 'x' || c == 'X')
        *result += print_hex(va_arg(args, size_t), c);
}

int	ft_printf(const char *str, ...)
{
    int result;
    va_list args;

    va_start(args, str);
    result = 0;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            check_modifier(*str, &result, args);
        }
        else
            result += ft_putchar(*str);
        str++;
    }
    va_end(args);
    return (result);
}