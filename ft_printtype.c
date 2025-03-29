/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <akopyanpyotrx99@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:29:12 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/26 21:23:24 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	if (!str)
		return (write(1, "(nil)", 5));
	return (write(1, str, ft_strlen(str)));
}

void	print_hex(unsigned int num, char spec, int *res)
{
	const char	*hex_digit;

	if (spec == 'x')
		hex_digit = "0123456789abcdef";
	else
		hex_digit = "0123456789ABCDEF";
	if (num / 16)
		print_hex(num / 16, spec, res);
	*res += ft_putchar(hex_digit[num % 16]);
}

void	print_pointer(unsigned long pt, int *res)
{
	if (!pt)
	{
		*res += print_string("(nil)");
		return ;
	}
	*res += write(1, "0x", 2);
	print_hex((unsigned long)pt, 'x', res);
}

void	print_unsigned(unsigned int n, int *res)
{
	if (n / 10 > 0)
		print_unsigned(n / 10, res);
	*res += ft_putchar((n % 10) + '0');
}

void	print_int(int n, int *res)
{
	if (n == -2147483648)
	{
		*res += write(1, "-2147483648", 11);
		return ;
	}	
	if (n < 0)
	{
		*res = ft_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_int(n / 10, res);
	*res += ft_putchar('0' + (n % 10));
}