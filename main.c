/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:28:38 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/24 20:47:22 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pip)
{
	dup2(pip->outfile, STDOUT_FILENO);
	execve(pip->path, pip->cmd1, NULL);
}

void	parent_process(t_pipex *pip)
{
	wait(&pip->pid);
	dup2(pip->infile, STDOUT_FILENO);
}

int	test_pip(char **argv, t_pipex *pip)
{
	int	i;
	// pid_t	pid;
	// char	buffer[13];

	i = -1;
	(void)*argv;
	while (++i <= 2)
	{
		if (pipe(pip->fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		pip->pid = fork();
		if (pip->pid == -1)
			return (ft_printf("Fail fork !\n"));
		if (pip->pid == 0) // child
			child_process(pip);
		if (pip->pid != 0) // paren
			parent_process(pip);
		close(pip->outfile);
		close(pip->infile);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pip;

	if (env != 0 && argc == 5)
	{
		init_struct(argv, &pip, env);
		find_path(&pip, env);
		// printf("\nFinal :::: %s\n", pip.path);
		test_pip(argv, &pip);
	}
	else
		return(ft_printf("Error !\nCheck number of arguments or your env!\n"));
	return (0);
}

// int main(int ac, char **av, char **envp)
// {
//     (void) ac;
//     (void) av;
//     const char *filename = "/usr/bin/grep";
//     char *const argv[] = {"/usr/bin/grep", "a", NULL};
    
//     execve(filename, argv, envp);
// }