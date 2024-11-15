/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:33:50 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/27 17:05:15 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	init_cmd(char **argv, t_pipex *pip)
// {
// 	int	i;

// 	i = 0;
// 	if (argv)
// 	{
// 		pip->cmd1 = ft_split(argv[2], ' ');
// 		if (!pip->cmd1)
// 			return ;
// 		pip->cmd2 = ft_split(argv[3], ' ');
// 		if (!pip->cmd2)
// 			return ;
// 	}
// }

int	init_struct(char **argv, t_pipex *pip, char **env)
{
	pip->path = NULL;
	pip->infile = open(argv[1], O_RDONLY, 0777);
	pip->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pip->env = env;
	pip->av = argv;
	pip->cmd = NULL;
	return (0);
}
