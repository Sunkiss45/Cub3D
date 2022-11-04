/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:34:21 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/04 17:28:42 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_jump_space(t_map *map)
{
	int	y;
	int	x;

	x = -1;
	while (1)
	{
		y = -1;
		x++;
		while (map->om[++y])
		{
			if (map->om[y][x] && map->om[y][x] == ' ')
				continue;
			else
				return (x);
		}
	}
	return (0);
}

bool	ft_check_char(char **map)
{
	int	y;
	int	x;
	int	p;
	int	m;

	y = -1;
	p = 0;
	while (map[++y])
	{
		x = -1;
		m = 0;
		while (map[y][++x])
		{
			if (!ft_strchr(map[y][x], "01NSEW "))
				return (false);
			if (ft_strchr(map[y][x], "01NSEW"))
				m++;
			if (ft_strchr(map[y][x], "NSEW"))
				p++;
		}
		if (!m)
			return (false);
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
	while (src && src[++i] && i < gsize)
		ret[i] = src[i];
	while (i < gsize)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

int	ft_retouch_while(t_map *map, int y, int j)
{
	char	*tmp;

	if (ft_strlen_nos(&map->om[y][j]) <= map->sizeline)
	{
		tmp = ft_resize_c(&map->om[y][j], map->sizeline, ' ');
		if (!tmp)
			return (ft_error_int("Malloc exception (ft_retouch)", 1));
		free (map->om[y]);
		map->om[y] = tmp;
	}
	// else if (ft_strlen(&map->om[y][j]) > map->sizeline)
	// {
	// 	tmp = ft_strdup_n(&map->om[y][j], map->sizeline);
	// 	if (!tmp)
	// 		return (ft_error_int("Malloc exception (ft_retouch)", 1));
	// 	free (map->om[y]);
	// 	map->om[y] = tmp;
	// }
	return (0);
}

int	ft_retouch(t_map *map)
{
	int		y;
	int		j;

	y = -1;
	j = ft_jump_space(map);
	while (map->om[++y])
		if (ft_strlen_nos(&map->om[y][j]) > map->sizeline)
			map->sizeline = ft_strlen_nos(&map->om[y][j]);
	map->nbline = y + 1;
	y = -1;
	while (map->om[++y])
		if (ft_retouch_while(map, y, j))
			return (1);
	return (0);
}

/*

	y = -1;
	i = -1;
	while (map->om[++y])
	{
		printf(BBLUE"[");
		x = -1;
		while (map->om[y][++x])
			printf("%c", map->map[++i]);
		printf("]"RESET"\n");
	}

*/

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

	y = -1;
	i = -1;
	while (map->om[++y])
	{
		printf(BBLUE"[");
		x = -1;
		while (map->om[y][++x])
			printf("%c", map->map[++i]);
		printf("]"RESET"\n");
	}

	map->map_ok = true;
	return (0);
}
