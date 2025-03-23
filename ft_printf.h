/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <akopyanpyotrx99@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:28:48 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/23 17:22:37 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int ft_putchar(char c);
int ft_printf(const char *str, ...);
int print_string(char *str);
int print_hex(size_t num, char spec);
int print_int(int n);
int print_unsigned(unsigned int n);
int print_pointer(size_t pt);
int ft_strlen(char *str);

#endif
