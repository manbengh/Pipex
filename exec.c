/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:52:27 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/27 18:27:55 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec(t_pipex *pip, int c)
{
	find_path(pip, pip->env, c);
	if (execve(pip->path, pip->cmd, pip->env) < 0)
	{
		free_everything(pip, "Error in execve !");
		exit(1);
	}
	return (1);
}

void	child_process1(t_pipex *pip)
{
	if (access(pip->av[1], R_OK) == -1 || pip->infile < 0)
		free_everything(pip, "Error ! File can't be opened ");
	if (dup2(pip->infile, STDIN_FILENO) < 0)
		free_everything(pip, "Error ! Dup2 Fail ");
	if (dup2(pip->fd[1], STDOUT_FILENO) < 0)
		free_everything(pip, "Error ! Dup2 Fail ");
	close_fd(pip);
	ft_exec(pip, 2);
}

void	child_process2(t_pipex *pip)
{
	if (access(pip->av[4], R_OK) == -1 || pip->outfile < 0)
		free_everything(pip, "Error ! File can't be opened ");
	if (dup2(pip->fd[0], STDIN_FILENO) < 0)
		free_everything(pip, "Error ! Dup2 Fail ");
	if (dup2(pip->outfile, STDOUT_FILENO) < 0)
		free_everything(pip, "Error ! Dup2 Fail ");
	close_fd(pip);
	ft_exec(pip, 3);
}
