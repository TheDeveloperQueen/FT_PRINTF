/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:00:32 by rivasque          #+#    #+#             */
/*   Updated: 2023/09/26 10:02:23 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_digit_base(unsigned long n, unsigned long base)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n < base)
		return (ft_putchar(hex[n]));
	else
	{
		count = ft_digit_base(n / base, base);
		return (count + ft_digit_base(n % base, base));
	}
}

int	ft_digit_base_up(unsigned long n, unsigned long base)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n < base)
		return (ft_putchar(hex[n]));
	else
	{
		count = ft_digit_base_up(n / base, base);
		return (count + ft_digit_base_up(n % base, base));
	}
}

int	ft_pointer(void *s)
{
	unsigned long	ptr;

	ptr = (unsigned long)s;
	write (1, "0x", 2);
	return (ft_digit_base(ptr, 16) + 2);
}
