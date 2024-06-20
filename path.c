/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:51 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/20 20:56:08 by manbengh         ###   ########.fr       */
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
	char	*res;

	get_path(env, pip, -1);
	while (pip->path_s[i] && pip->cmd1)
	{
		res = ft_strjoin(pip->path_s[i], "/");
		printf("with / at the end %s\n", res);
		res = ft_strjoin(res, pip->cmd1[0]);
		printf("res = %s\n", res);
		if (access(res, F_OK | X_OK) == 0)
		{
			printf("access\n");
			pip->path = res;
		}
		free(res);
		i++;
	}
	printf("final :::: %s\n", pip->path);
	perror(pip->cmd1[0]);
}
