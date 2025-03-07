/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:02:26 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/07 20:23:22 by pakopian         ###   ########.fr       */
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

int	print_number
{
	
}

int	print_unsigned


