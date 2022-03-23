/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/13 20:26:32 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *stack, const char *needle, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*get_next_line(void);
char	*ft_strnjoin(char *s1, char *s2);
char	*first_step(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
void	ft_find_path(char **env, char *argv);
char	**ft_srch_path(char **cmd, int i, char **env, char	**paths);
char	**ft_exec_path(char **paths, char **cmd, char **env);
void	ft_multipipe(int argc, char **argv, int *pipe_fd, char **env);
void	ft_here_doc(char **argv, int *pipe_fd);
void	ft_parrent(int argc, char **argv, char **env, int *pipe_fd);
void	ft_child(char **argv, char **env, int *pipe_fd, int *pipe_fd2);
void	ft_multipipe(int argc, char **argv, int *pipe_fd, char **env);
void	ft_free( char **a);
void	ft_close( int *pipe_fd);
void	ft_close_fd(int argc, int **multipipe, int *pipe_fd);
void	ft_dup_close(char **argv, char **env, int *pipe_fd, int *pipe_fd2);

#endif
