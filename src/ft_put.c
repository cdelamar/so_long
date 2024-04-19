/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:10:33 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 21:51:16 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

// int	ft_unsigned_nbr(unsigned int n)
// {
//     int count;
//     long nb;
//     count = 0;
//     nb = (long)n;
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = -nb;
//         count++;
// 	}
// 	if (n <= 9)
// 	{
// 		ft_putchar((n + '0'));
//         return (++count);
// 	}
// 	count += ft_putnbr(n / 10);
// 	count += ft_putnbr(n % 10);
//     return (count);
// }
// int	ft_putnbr(int n)
// {
//     int count;
//     long nb;
//     count = 0;
//     nb = (long)n;
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = -nb;
//         count++;
// 	}
// 	if (nb <= 9)
// 	{
// 		ft_putchar((nb + '0'));
//         return (++count);
// 	}
// 	count += ft_putnbr(nb / 10);
// 	count += ft_putnbr(nb % 10);
//     return (count);
// }
//---------------------------------------------------
// int	ft_putnbr(int n)
// {
//     int count;
//     count = 0;
// 	if (n == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return (11) ;
// 	}
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		n = -n;
//         count++;
// 	}
// 	if (n <= 9)
// 	{
// 		ft_putchar((n + '0'));
// 		count++;
//         return (count);
// 	}
// 	count += ft_putnbr(n / 10);
// 	count += ft_putnbr(n % 10);
//     return (count);
// }
