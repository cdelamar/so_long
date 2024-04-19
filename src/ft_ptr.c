/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:54:37 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/11 21:51:13 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_address(void *ptr)
{
	unsigned long long	i;

	i = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_print_hex(i, 'x'));
}
