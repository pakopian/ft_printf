/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <akopyanpyotrx99@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:29:12 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/23 17:22:37 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	if (!str)
		return (write(1, "(nil)", 5));
	return (write(1, str, ft_strlen(str)));
}

int	print_hex(size_t num, char spec)
{
	char	*hex_digit;
	char	buffer[16];
	int		i;
	int		n;

	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	if (spec == 'x')
		hex_digit = "0123456789abcdef";
	else
		hex_digit = "0123456789ABCDEF";
	while (num)
	{
		buffer[i++] = hex_digit[num % 16];
		num /= 16;
	}
	n = i;
	while (i--)
		write(1, &buffer[i], 1);
	return (n);
}

int	print_pointer(size_t pt)
{
	if (!pt)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + print_hex(pt, 'x'));
}

int	print_unsigned(unsigned int n)
{
	char	c;
	int		result;
	unsigned int		i;

	if (n == 0)
		return (write(1, "0", 1));
	i = n;
	while (i)
	{
		i /= 10;
		result++;
	}
	if (n / 10 > 0)
		print_unsigned(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	return (result);
}

int	print_int(int n)
{
	char	c;
	int		result;
	int		i;

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