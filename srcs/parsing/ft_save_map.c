/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:34:21 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/03 04:12:49 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_char(char **map)
{
	int	y;
	int	x;
	int	p;

	y = -1;
	p = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_strchr(map[y][x], "01NSEW "))
				return (false);
			if (ft_strchr(map[y][x], "NSEW"))
				p++;
		}
	}
	if (p != 1)
		return (false);
	return (true);
}

char	*ft_resize_c(char *src, int gsize, char c)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * gsize + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (src && src[++i])
		ret[i] = src[i];
	while (i < gsize)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

int	ft_retouch(t_map *map)
{
	char	*tmp;
	int		y;

	y = -1;
	while (map->om[++y])
		if (ft_strlen(map->om[y]) > map->sizeline)
			map->sizeline = ft_strlen(map->om[y]);
	map->nbline = y + 1;
	y = -1;
	while (map->om[++y])
	{
		if (ft_strlen(map->om[y]) < map->sizeline)
		{
			tmp = ft_resize_c(map->om[y], map->sizeline, ' ');
			if (!tmp)
				return (ft_error_int("Malloc exception (ft_retouch)", 1));
			free (map->om[y]);
			map->om[y] = tmp;
		}
	}
	return (0);
}

int	ft_save_map(t_map *map)
{
	int	x;
	int	y;
	int	i;

	if (!ft_check_char(map->om))
		return (1);
	if (ft_retouch(map))
		return (1);
	if (!ft_verify_close_map(map))
		return (1);
	map->map = malloc(sizeof(int) * (map->sizeline * map->nbline));
	if (!map->map)
		return (ft_error_int("Exception malloc (ft_save_map)", 1));
	y = -1;
	i = -1;
	while (map->om[++y])
	{
		x = -1;
		while (map->om[y][++x])
			map->map[++i] = map->om[y][x];
	}
	map->map_ok = true;
	return (0);
}
