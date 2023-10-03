/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:38:14 by rivasque          #+#    #+#             */
/*   Updated: 2023/09/25 21:24:18 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_digit_base(unsigned long n, unsigned long base);
int	ft_digit_base_up(unsigned long n, unsigned long base);
int	ft_pointer(void *s);
int	ft_printf(const char *str, ...);

#endif