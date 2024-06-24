/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:51 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/24 20:32:27 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(char **env, t_pipex *pip, int i)
{
	int	j;
	int	u = 5;

	j = 0;
	while (env[++i])
	{
		while (env[i][j] == "PATH="[j])
		{
			j++;
			if (j == 5 && env[i][u])
			{
				pip->path_s = ft_split(&env[i][u], ':');
				break;
			}
		}
	}
	// i = 0;
	// while (pip->path_s[i])
	// {
	// 	printf("%s\n", pip->path_s[i]);
	// 	i++;
	// }
}

void	find_path(t_pipex *pip, char **env)
{
	int i = 0;
	char	*tmp;

	get_path(env, pip, -1);
	while (pip->path_s[i] && pip->cmd1)
	{
		tmp = ft_strjoin(pip->path_s[i], "/");
		tmp = ft_strjoin(tmp, pip->cmd1[0]);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			pip->path = tmp;
			// free(tmp);
			return ;
		}
		free(tmp);
		i++;
	}
	perror(pip->cmd1[0]);
}
