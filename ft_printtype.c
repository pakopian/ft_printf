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

int	print_hex(unsigned long long num, char spec)
{
	const char	*hex_digit;
	int			n;

	if (num == 0)
		return (write(1, "0", 1));
	if (spec == 'x')
		hex_digit = "0123456789abcdef";
	else
		hex_digit = "0123456789ABCDEF";
	if (num / 16)
		n = print_hex(num / 16, spec);
	else
		n = 0;
	ft_putchar(hex_digit[num % 16]);
	return (n + 1);
}

int	print_pointer(unsigned long long pt)
{
	if (!pt)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + print_hex((unsigned long long)pt, 'x'));
}

int	print_unsigned(unsigned int n)
{
	char	c;
	int		result;

	result = 1;
	if (n / 10 > 0)
		result += print_unsigned(n / 10);

	c = '0' + (n % 10);
	write(1, &c, 1);
	return (result);
}

int	print_int(int n)
{
	char	c;
	int		result;
	int		i;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n == 0)
		return (write(1, "0", 1));
	i = n;
	result = 0;
	if (n < 0)
	{
		result = ft_putchar('-');
		n = -n;
	}
	while (i)
	{
		i /= 10;
		result++;
	}
	if (n / 10 > 0)
		print_int(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	return (result);
}