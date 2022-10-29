/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_prem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:49:41 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/29 17:42:31 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	error_gnl_prem(char **l, int fd)
{
	free(*l);
	*l = gnl(fd);
	return (true);
}

static char	*join_bis(char *l, char *j)
{
	char	*tmp;

	tmp = j;
	j = ft_strjoin_c(tmp, l, '\n');
	if (tmp)
		free(tmp);
	if (!j)
		return (NULL);
	return (j);
}

char	**ft_gnl_prem(int fd)
{
	char	**ret;
	char	*j;
	char	*l;
	bool	e;

	ret = NULL;
	j = NULL;
	l = gnl(fd);
	e = false;
	while (l)
	{
		if (e && error_gnl_prem(&l, fd))
			continue ;
		j = join_bis(l, j);
		if (!j)
			e = true;
		free(l);
		l = gnl(fd);
	}
	if (!j)
		return (NULL);
	ret = ft_split_lib(j, '\n');
	if (!ret)
		return (free(j), NULL);
	return (free(j), ret);
}
