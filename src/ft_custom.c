/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:53:56 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/22 23:28:34 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rev_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (len1 && len2 && n)
	{
		if (s1[len1 -1] != s2[len2 -1])
			return (s1[len1 -1] - s2[len2 -1]);
		len1--;
		len2--;
		n--;
	}
	if (n == 0)
		return (0);
	return (len1 - len2);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_putnbr(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb <= 9)
	{
		ft_putchar((nb + '0'));
		return (++count);
	}
	count += ft_putnbr(nb / 10);
	count += ft_putnbr(nb % 10);
	return (count);
}

int	ft_unsigned_nbr(unsigned int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (n <= 9)
	{
		ft_putchar((n + '0'));
		return (++count);
	}
	count += ft_putnbr(n / 10);
	count += ft_putnbr(n % 10);
	return (count);
}
