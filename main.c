/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:28:38 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/20 16:51:23 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test_pip(char **argv, t_pipex *pip)
{
	int		fd[2];
	pid_t	pid;

	(void)*pip;
	fd[0] = open(argv[1], O_WRONLY | O_CREAT);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0 || access(argv[1], R_OK) == -1 || access(argv[4], R_OK) == -1)
		return (ft_printf("Error !\nFile can't be opened\n"), 0);
	pid = fork();
	if (pid == -1)
		return (ft_printf("Fail fork !\n"));
	// execute code then
	if (pid == 0) // child
	{
		dup2(fd[1], STDOUT_FILENO);
		ft_printf("Child !\nOutfile test\n");
	}
	if (pid != 0) // parent
	{
		dup2(fd[0], STDOUT_FILENO);
		ft_printf("Parent !\n");
	}
	close(fd[1]);
	close(fd[0]);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pip;

	if (env != 0 && argc == 5)
	{
		init_struct(argv, &pip);
		// test_pip(argv, &pip);
		find_path(&pip, env);
	}
	return (0);
}
