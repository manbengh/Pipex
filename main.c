/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:28:38 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/26 21:27:56 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec(t_pipex *pip, int c)
{
	find_path(pip, pip->env, c);
	if (execve(pip->path, pip->cmd, pip->env) < 0)
	{
		free_everything(pip);
		exit (1);
	}
	return (1);
}

void	child_process1(t_pipex *pip)
{
	if (dup2(pip->infile, STDIN_FILENO) < 0)
		dprintf(2, "1dup2 fail\n");
	if (dup2(pip->fd[1], STDOUT_FILENO) < 0)
		dprintf(2, "dup2 fail\n");
	close_fd(pip);
	ft_exec(pip, 2);
}

void	child_process2(t_pipex *pip)
{
	if (dup2(pip->fd[0], STDIN_FILENO) < 0)
		dprintf(2, "child2 dup2 fail\n");
	if (dup2(pip->outfile, STDOUT_FILENO) < 0)
		dprintf(2, "1child2 dup2 fail\n");
	close_fd(pip);
	ft_exec(pip, 3);
}

int	pipex(t_pipex *pip)
{
	if (pipe(pip->fd) == -1)
	{
		close_fd(pip);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pip->pid1 = fork();
	if (pip->pid1 < 0)
		return (ft_printf("Failed fork !\n"));
	if (pip->pid1 == 0) // child 1
		child_process1(pip);
	pip->pid2 = fork();
	if (pip->pid2 < 0)
		return (ft_printf("Failed fork !\n"));
	if (pip->pid2 == 0) // child 2
		child_process2(pip);
	close_fd(pip);
	while (wait(NULL) > 0)
		;
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pip;

	if (env != 0 && argc == 5)
	{
		init_struct(argv, &pip, env);
		pipex(&pip);
	}
	else
		return(ft_printf("Error !\nCheck number of arguments or your env!\n"));
	return (0);
}
