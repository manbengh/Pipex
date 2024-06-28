/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:28:38 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/27 18:19:23 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_pipex *pip)
{
	if (pipe(pip->fd) == -1)
	{
		close_fd(pip);
		perror("Pipe Error !\n");
		exit(EXIT_FAILURE);
	}
	pip->pid1 = fork();
	if (pip->pid1 < 0)
		return (ft_printf("Failed fork !\n"));
	if (pip->pid1 == 0)
		child_process1(pip);
	pip->pid2 = fork();
	if (pip->pid2 < 0)
		return (ft_printf("Failed fork !\n"));
	if (pip->pid2 == 0)
		child_process2(pip);
	close_fd(pip);
	while (wait(NULL) > 0)
		;
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pip;

	if (argc == 5)
	{
		init_struct(argv, &pip, env);
		pipex(&pip);
	}
	else
		return (ft_printf("Error !\nCheck number of arguments !\n"));
	return (0);
}
