/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:47:58 by minell            #+#    #+#             */
/*   Updated: 2022/03/13 20:27:44 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	**ft_exec_path(char **paths, char **cmd, char **env)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp1 = ft_strjoin(paths[i], "/");
		tmp2 = ft_strjoin(tmp1, cmd[0]);
		if (!tmp2)
		{
			ft_free(cmd);
			ft_free(paths);
		}
		free(tmp1);
		if (access(tmp2, F_OK) == 0)
		{
			ft_free(paths);
			execve(tmp2, cmd, env);
		}
		else
			free(tmp2);
		i++;
	}
	return (paths);
}

char	**ft_srch_path(char **cmd, int i, char **env, char	**paths)
{
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
	{
		i++;
		if (env[i] == NULL)
		{
			ft_free(cmd);
			exit (1);
		}
	}
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
	{
		ft_free(cmd);
		exit (1);
	}
	paths = ft_exec_path(paths, cmd, env);
	return (paths);
}

void	ft_find_path(char **env, char *argv)
{
	int		i;
	char	**cmd;
	char	**cmd2;
	char	**cmd3;
	char	**paths;

	i = 0;
	paths = NULL;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], F_OK) == 0)
	{
		cmd3 = ft_split(argv, '/');
		while (cmd3[i])
			i++;
		cmd2 = ft_split(cmd3[i -1], ' ');
		ft_free(cmd3);
		execve(cmd[0], &cmd2[0], env);
	}
	paths = ft_srch_path(cmd, i, env, paths);
	ft_free(cmd);
	ft_free(paths);
	write(2, "pipex: Wrong cmd\n", 17);
	exit (1);
}
