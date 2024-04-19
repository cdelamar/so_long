/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:13:14 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/19 15:14:49 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*ft_substr*/
/*sur la chaine '*s' copie en commencant a
partir de 'start' sur 'len' caracteres*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = start;
	j = 0;
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (len > 0 && s[i])
	{
		str[j++] = s[i++];
		len--;
	}
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
		char tab[] = "test toast";
		char *tab2;

		tab2 = ft_substr(tab, 9999999, 99999);

		printf("char *s : %s$\n", tab);
		printf("returned : %s$\n", tab2);

		free(tab2);

		return (0);
}*/