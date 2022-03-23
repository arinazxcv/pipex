/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:53:36 by minell            #+#    #+#             */
/*   Updated: 2022/03/10 11:57:36 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
/**
 * делит строку разделителем с
 * на подстроки.
 */
static size_t	ft_words(char const *s, char c)
{
	size_t	qts;
	size_t	i;

	qts = 0;
	i = 0;
	while (s && s[i])
	{		
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			qts++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (qts);
}

static char	**ft_free_1(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static size_t	ft_lengw(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_writew(const char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*arr;

	i = 0;
	len = ft_lengw(s, c);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	while (i < len && s[i])
	{
		arr[i] = s[i];
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		qts;
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	qts = ft_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (qts + 1));
	if (arr == NULL)
		return (NULL);
	arr[qts] = 0;
	i = -1;
	while (++i < qts)
	{
		while (s[0] == c)
			s++;
		arr[i] = ft_writew(s, c);
		if (!(arr[i]))
			return (ft_free_1(arr));
		s = s + ft_strlen(arr[i]);
	}
	return (arr);
}
