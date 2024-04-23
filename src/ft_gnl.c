/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:03:25 by cdelamar          #+#    #+#             */
/*   Updated: 2024/04/22 23:20:51 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
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
	ft_strcpy(ss1, s1);
	ft_strcpy(ss2, s2);
	ft_strcpy(str, ss1);
	st_strcat(str, ss2);
	free(ss1);
	free(ss2);
	return (str);
}
