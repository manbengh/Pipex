/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:53:12 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/24 20:39:40 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

	typedef struct s_pipex
	{
		int	fd[2];
		pid_t	pid;
		int	infile;
		int	outfile;
		char 	**env;
		char	**inf_cont;
		char	**path_s;
		char	*path;
		char	**cmd1;
		char	**cmd2;
	}			t_pipex;



int			test_pip(char **argv, t_pipex *pip);
void		init_cmd(char **argv, t_pipex *pip);
int		init_struct(char **argv, t_pipex *pip, char **env);
int			ft_strcompa(const char *s1, const char *s2);
void		get_path(char **env, t_pipex *pip, int i);
void		find_path(t_pipex *pip, char **env);
void	child_process(t_pipex *pip);
void	parent_process(t_pipex *pip);

#endif