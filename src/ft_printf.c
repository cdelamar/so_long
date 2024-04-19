/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:00:37 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 21:52:53 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	specifier(const char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		i += print_address(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_unsigned_nbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		i += ft_percent();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += specifier(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			++counter;
		}
		++i;
	}
	return (counter);
}
