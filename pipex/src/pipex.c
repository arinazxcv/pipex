/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:47:58 by minell            #+#    #+#             */
/*   Updated: 2022/03/13 20:26:59 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_here_doc(char **argv, int *pipe_fd)
{
	char	*temp;
	char	*temp2;
	char	*temp3;

	temp = NULL;
	temp2 = NULL;
	while (ft_strcmp(temp2, argv[2]) != 0)
	{
		temp = ft_strnjoin(temp, temp2);
		free(temp2);
		write(1, "pipe heredoc> ", 14);
		temp2 = get_next_line();
	}
	temp3 = ft_strjoin(temp, "\n");
	if (pipe(pipe_fd) == -1)
		exit (1);
	write(pipe_fd[1], temp3, ft_strlen(temp3));
	free(temp);
	free(temp2);
	free(temp3);
}

void	ft_parrent(int argc, char **argv, char **env, int *pipe_fd)
{
	int	fd_file;

	if (argc > 5 && ft_strcmp(argv[1], "here_doc") != 0)
		ft_multipipe(argc, argv, pipe_fd, env);
	else if (argc > 6 && ft_strcmp(argv[1], "here_doc") == 0)
		ft_multipipe(argc - 1, argv, pipe_fd, env);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		fd_file = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 422);
	else
		fd_file = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 422);
	if (fd_file == -1)
		exit (1);
	dup2(pipe_fd[0], 0);
	dup2(fd_file, 1);
	close(fd_file);
	ft_close(pipe_fd);
	ft_find_path(env, argv[argc - 2]);
}

void	ft_child(char **argv, char **env, int *pipe_fd, int *pipe_fd2)
{
	int	fd_file;

	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_dup_close(argv, env, pipe_fd, pipe_fd2);
	if (access(argv[1], F_OK) != 0)
	{
		write(2, "pipex: Wrong file name\n", 23);
		exit(1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		write(2, "pipex: no rights\n", 17);
		exit(1);
	}
	if (ft_strcmp(argv[1], argv[4]) != 0)
		fd_file = open(argv[1], O_RDONLY);
	else
		fd_file = open(argv[1], O_RDONLY | O_TRUNC);
	dup2(fd_file, 0);
	dup2(pipe_fd[1], 1);
	ft_close(pipe_fd);
	ft_close(pipe_fd2);
	ft_find_path(env, argv[2]);
}

int	main(int argc, char **argv, char **env)
{
	int	pid;
	int	pipe_fd[2];
	int	pipe_fd2[2];

	if (argc < 5)
		return (1);
	if (pipe(pipe_fd) == -1)
		return (1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_here_doc(argv, pipe_fd);
	if (pipe(pipe_fd2) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
		ft_child(argv, env, pipe_fd, pipe_fd2);
	if (ft_strcmp(argv[1], "here_doc") != 0)
		ft_parrent(argc, argv, env, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_parrent(argc, argv, env, pipe_fd2);
}
