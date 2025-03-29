/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <akopyanpyotrx99@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:28:48 by pakopian          #+#    #+#             */
/*   Updated: 2025/03/26 21:23:23 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int ft_putchar(char c);
int ft_printf(const char *str, ...);
int print_string(char *str);
void print_hex(unsigned int num, char spec, int *res);
void print_int(int n, int *res);
void print_unsigned(unsigned int n, int *res);
void print_pointer(unsigned long pt, int *res);
int ft_strlen(char *str);

#endif
