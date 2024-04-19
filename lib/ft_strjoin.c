/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:12:43 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/20 15:56:29 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static char	*st_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*st_strcpy(char *dest, const char *src)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*str;
	char	*ss1;
	char	*ss2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ss1 = (char *)malloc(len1 * sizeof(char) + 1);
	ss2 = (char *)malloc(len2 * sizeof(char) + 1);
	str = (char *)malloc(len1 * sizeof(char) + len2 * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	st_strcpy(ss1, s1);
	st_strcpy(ss2, s2);
	st_strcpy(str, ss1);
	st_strcat(str, ss2);
	return (str);
}
/*
int	main(void)
{
		char    tab1[] = "mais si, ";
		char    tab2[] = "ca marche";
		char    *tab_ft;

		tab_ft = ft_strjoin(tab1, tab2);
		printf("%s\n", tab_ft);

		free(tab_ft);
		return (0);
}*/