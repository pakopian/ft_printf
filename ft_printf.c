/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:57:18 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/29 19:58:05 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

static void	check_modifier(char c, int *result, va_list args)
{
	if (c == '%')
		*result += ft_putchar('%');
	else if (c == 'c')
		*result += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*result += print_string(va_arg(args, char *));
	else if (c == 'p')
		print_pointer(va_arg(args, unsigned long), result);
	else if (c == 'i' || c == 'd')
		print_int(va_arg(args, int), result);
	else if (c == 'u')
		print_unsigned(va_arg(args, unsigned int), result);
	else if (c == 'x' || c == 'X')
		print_hex(va_arg(args, unsigned int), c, result);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

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
