/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:29:12 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/18 21:46:45 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	return(write(1, *str, ft_strlen(str));
}

int	print_hex(size_t num, char spec)
{
	char	*hex_digit;
	char	buffer[20];
	int		i;
	int		n;

	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	if (spec == 'x')
		*hex_digit = "0123456789abcdef";
	else
		*hex_digit = "0123456789ABCDEF";
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
	write(1, "0x", 2);
	return (2 + print_hex(num, 'x'))
}

int	print_number(int n)
{
	if (n == -2147483648)
	{
        	write(1, "-2147483648", 11);
        	return;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	print_unsigned


