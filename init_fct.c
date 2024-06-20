/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:33:50 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/20 20:38:11 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd(char **argv, t_pipex *pip)
{
	int	i;

	i = 0;
	if (argv)
	{
		pip->cmd1 = ft_split(argv[2], ' ');
		if (!pip->cmd1)
			return ;
		pip->cmd2 = ft_split(argv[3], ' ');
		if (!pip->cmd2)
			return ;
	}
}

void	init_struct(char **argv, t_pipex *pip)
{
	pip->inf_cont = NULL;
	pip->cmd1 = NULL;
	pip->cmd2 = NULL;
	pip->path_s = NULL;
	pip->path = NULL;
	init_cmd(argv, pip);
}