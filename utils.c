/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manbengh <manbengh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:52 by manbengh          #+#    #+#             */
/*   Updated: 2024/06/20 16:00:46 by manbengh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcompa(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while (s1[i] && s2[i])
	{
		u1 = (unsigned char)s1[i];
		u2 = (unsigned char)s2[i];
		if (u1 != u2 || u1 == '\0' || u2 == '\0')
			return (u1 - u2);
		i++;
	}
	return (0);
}
