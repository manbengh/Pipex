/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:53:12 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/27 17:57:17 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	**env;
	char	**av;
	char	*path;
	char	**cmd;
}			t_pipex;

int			pipex(t_pipex *pip);
int			init_struct(char **argv, t_pipex *pip, char **env);
char		**get_path(char **env);
int			concatene_command(t_pipex *pip, char **s_path);
void		find_path(t_pipex *pip, char **env, int c);
void		child_process1(t_pipex *pip);
void		child_process2(t_pipex *pip);

void		free_everything(t_pipex *pip, char *str);
void		free_tab(char **tab);
void		close_fd(t_pipex *pip);

#endif