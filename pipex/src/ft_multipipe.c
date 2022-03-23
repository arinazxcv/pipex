/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multipipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:47:58 by minell            #+#    #+#             */
/*   Updated: 2022/03/13 20:28:43 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	**ft_init_mult(int argc, int i, int **multpipe)
{
	i = -1;
	multpipe = malloc(sizeof(int *) * argc - 5);
	if (!multpipe)
		exit(0);
	while (++i < argc - 5)
	{
		multpipe[i] = malloc(sizeof(int) * 2);
		if (!multpipe[i])
			exit(0);
		if (pipe(multpipe[i]) == -1)
			exit(1);
	}
	return (multpipe);
}

void	ft_pid_cild(int **multpipe, int *pipe_fd, int i)
{
	if (i == 0)
	{
		dup2(pipe_fd[0], 0);
		dup2(multpipe[i][1], 1);
	}
	else
	{
		dup2(multpipe[i - 1][0], 0);
		dup2(multpipe[i][1], 1);
	}
}

void	ft_files(int argc, char **argv, int **multpipe, int *pipe_fd)
{
	int	fd_file;
	int	i;

	i = argc - 5;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		fd_file = open(argv[argc], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd_file = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_file == -1)
		exit (1);
	dup2(multpipe[i - 1][0], 0);
	dup2(fd_file, 1);
	ft_close_fd(argc, multpipe, pipe_fd);
	close(fd_file);
}

void	ft_multipipe(int argc, char **argv, int *pipe_fd, char **env)
{
	int	i;
	int	pid;
	int	**multpipe;

	i = -1;
	multpipe = NULL;
	multpipe = ft_init_mult(argc, i, multpipe);
	while (++i < argc - 5)
	{
		pid = fork();
		if (pid == -1)
			exit (1);
		if (pid == 0)
		{
			ft_pid_cild(multpipe, pipe_fd, i);
			ft_close_fd(argc, multpipe, pipe_fd);
			if (ft_strcmp(argv[1], "here_doc") == 0)
				ft_find_path(env, argv[i + 4]);
			ft_find_path(env, argv[i + 3]);
		}
	}
	ft_files(argc, argv, multpipe, pipe_fd);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_find_path(env, argv[argc - 1]);
	ft_find_path(env, argv[argc - 2]);
}
