/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:13:39 by minell            #+#    #+#             */
/*   Updated: 2022/03/10 14:32:57 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*get_next_line(void)
{
	int		j;
	char	*buf;
	char	*line;
	char	*tmp;

	line = NULL;
	while (1)
	{
		buf = malloc(sizeof(char) + 1);
		j = read(0, buf, 1);
		if (buf[0] == '\n' || buf[0] == '\0')
			break ;
		buf[1] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
		free(buf);
	}
	free(buf);
	return (line);
}

char	*first_step(char *str)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char *) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strnjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (first_step(s2));
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\n';
	j = 0;
	while (s2[++j - 1])
		res[i + j] = s2[j - 1];
	res[i + j] = '\0';
	free(s1);
	return (res);
}
