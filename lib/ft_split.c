/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:12:32 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/19 15:14:09 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	words_counter(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static size_t	get_word_size(char const *s, char c)
{
	size_t	word_size;

	word_size = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		word_size++;
		s++;
	}
	return (word_size);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		words;
	size_t	word_size;

	i = 0;
	words = words_counter(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_size = get_word_size(s, c);
			res[i++] = ft_substr(s, 0, word_size);
			s += word_size;
		}
	}
	res[i] = NULL;
	return (res);
}
/*
static int	words_counter(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		words;
	size_t	word_size;

	i = 0;
	words = words_counter(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_size = ft_strlen(s);
			else
				word_size = ft_strchr(s, c) - s;
			res[i++] = ft_substr(s, 0, word_size);
			s += word_size;
		}
	}
	res[i] = NULL;
	return (res);
}

int	main(void)
{
	char tab[] = "test toast taste";
	char    **res = ft_split(tab, ' ');
	int i = 0;

	while(res[i] != NULL)
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}*/