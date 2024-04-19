/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:13:08 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/19 15:14:46 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (&(str[i]));
		i--;
	}
	return (NULL);
}

/*int main()
{
	char tab[] = "hello, is it me youre looking for ?";
	char *res;
	res = strrchr(tab, 'o');

	char *resft;
	resft = ft_strrchr(tab, 'o');

	printf("%s founded, location : %p\n", res, res);

	printf("%s founded, location : %p\n", resft, resft);

}*/