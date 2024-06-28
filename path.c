/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:51 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/27 18:27:34 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	int		j;
	int		i;
	int		u;
	char	**res;

	u = 5;
	j = 0;
	i = -1;
	while (env[++i])
	{
		while (env[i][j] == "PATH="[j])
		{
			j++;
			if (j == 5 && env[i][u])
			{
				res = ft_split(&env[i][u], ':');
				return (res);
			}
		}
	}
	return (NULL);
}

int	concatene_command(t_pipex *pip, char **s_path)
{
	int		i;
	char	*tmp;
	char	*full_command;

	i = 0;
	tmp = NULL;
	full_command = NULL;
	while (s_path && s_path[i] && pip->cmd)
	{
		tmp = ft_strjoin(s_path[i], "/");
		full_command = ft_strjoin(tmp, pip->cmd[0]);
		free(tmp);
		if (access(full_command, F_OK | X_OK) == 0)
		{
			pip->path = full_command;
			if (s_path)
				free_tab(s_path);
			return (1);
		}
		free(full_command);
		i++;
	}
	return (0);
}

void	find_path(t_pipex *pip, char **env, int c)
{
	char	**s_path;

	if (access(pip->av[c], F_OK | X_OK) == 0)
	{
		pip->path = pip->av[c];
		return ;
	}
	s_path = get_path(env);
	pip->cmd = ft_split(pip->av[c], ' ');
	if (concatene_command(pip, s_path) == 1)
		return ;
	free_tab(s_path);
	free_everything(pip, "Error ! Can't find path ");
}
