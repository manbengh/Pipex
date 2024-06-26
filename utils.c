/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:52 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/26 21:35:03 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_path(char *str, t_pipex *pip)
{
	perror(str);
	free(pip->path);
	exit (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_everything(t_pipex *pip)
{
	if (pip->cmd)
		free_tab(pip->cmd);
	if (pip->path)
		free(pip->path);
	close_fd(pip);
	exit(1);
}

void	close_fd(t_pipex *pip)
{
	close(pip->fd[1]);
	close(pip->fd[0]);
	close(pip->infile);
	close(pip->outfile);
}
