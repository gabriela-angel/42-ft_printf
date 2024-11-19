/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:03:18 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/14 15:21:19 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	wordcount;
	int		i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			wordcount++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wordcount);
}

static void	free_split(char **arr, int j)
{
	while (j >= 0)
		free(arr[j--]);
	free(arr);
	return ;
}

static size_t	wordlen(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	populate_arr(char **arr, char const *s, char c)
{
	size_t	len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		len = wordlen(s, c, i);
		arr[j] = ft_substr(s, i, len);
		if (!arr[j])
		{
			free_split(arr, j);
			return (0);
		}
		i += len;
		j++;
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s, c);
	arr = malloc((wordcount + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (populate_arr(arr, s, c) == 0)
		return (NULL);
	return (arr);
}
