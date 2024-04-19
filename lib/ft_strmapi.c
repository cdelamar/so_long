/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:12:58 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/20 02:23:39 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	i = 0;
	if (!s || !f || !str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	testindex(unsigned int index, char c)
{
		char res;
		res = '0' + (index % 10);       // %10 sinon "123456789:;<=>..."
		return (res);                   // au lieu de "123456789123..."
}*/

/*int     main()
{
		char tab[] = "jai la peche";
		printf("%s\n", tab);

		printf("%s\n", ft_strmapi(tab, replace_with_index));
		printf("%s\n", tab);

		return (0);
}*/