/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:51 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/26 21:34:09 by manbengh         ###   ########.fr       */
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

void	find_path(t_pipex *pip, char **env, int c)
{
	int		i;
	char	*tmp;
	char	**s_path;

	i = 0;
	s_path = get_path(env);
	if (!s_path)
		free_everything(pip);
	pip->cmd = ft_split(pip->av[c], ' ');
	while (s_path[i] && pip->cmd)
	{
		tmp = ft_strjoin(s_path[i], "/");
		tmp = ft_strjoin(tmp, pip->cmd[0]);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			pip->path = tmp;
			return ;
		}
		free(tmp);
		i++;
	}
	free_tab(s_path);
}
