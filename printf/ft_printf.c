/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:43:19 by rivasque          #+#    #+#             */
/*   Updated: 2023/09/26 10:01:01 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(const char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_digit_base(va_arg(ap, unsigned int), 10));
	else if (c == 'x')
		return (ft_digit_base(va_arg(ap, unsigned int), 16));
	else if (c == 'X')
		return (ft_digit_base_up(va_arg(ap, unsigned int), 16));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		output;
	int		i;

	va_start(ap, str);
	output = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
			output++;
		}
		else
		{
			output += ft_type(str[i + 1], ap);
			i += 2;
		}
	}
	va_end(ap);
	return (output);
}
