/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:47:58 by minell            #+#    #+#             */
/*   Updated: 2022/03/13 19:05:59 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_free( char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}

void	ft_close( int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	ft_close_fd(int argc, int **multipipe, int *pipe_fd)
{
	int	i;

	i = -1;
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (++i < argc - 5)
	{
		close(multipipe[i][0]);
		close(multipipe[i][1]);
	}
}

void	ft_dup_close(char **argv, char **env, int *pipe_fd, int *pipe_fd2)
{
	dup2(pipe_fd[0], 0);
	dup2(pipe_fd2[1], 1);
	ft_close(pipe_fd);
	ft_close(pipe_fd2);
	ft_find_path(env, argv[3]);
}
