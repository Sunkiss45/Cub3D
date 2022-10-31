/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:46:35 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/31 03:59:07 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*ft_free_split(char **strs)
{
	int	i;

	i = -1;
	if (strs)
	{
		while (strs[++i])
			free(strs[i]);
		free(strs);
	}
	return (NULL);
}

bool	ft_elems_ok(t_map *map)
{
	if (!map->tex_no)
		return (false);
	if (!map->tex_so)
		return (false);
	if (!map->tex_we)
		return (false);
	if (!map->tex_ea)
		return (false);
	if (map->flo == -1)
		return (false);
	if (map->cel == -1)
		return (false);
	return (true);
}

void	ft_get_map(t_map *map, char *l)
{
	int	i;

	if (map->om)
	{
		printf(PINK"Detected already on map"RESET"\n"); // go to ft_save_map
		return ;
	}
	i = -1;
	while (l[++i])
		if (!ft_strchr(l[i], "01NSEW "))
			return ;
	map->om = true;
	printf(PINK"Detected on map"RESET"\n");

	return ;
}

/*
	int	x = -1;
	while (data[++x])
		printf(BRED"[%s]"RESET"\n", data[x]);
*/

int	ft_read_data(t_map *map)
{
	char	**data;
	int		y;
	int		i;

	data = ft_gnl_prem(map->fd);
	if (!data)
		return (ft_error_int("Error while read the file", 1));
	y = -1;
	while (data[++y])
	{
		printf(CYAN"[%s]"RESET"\n", data[y]);
		i = 0;
		while (data[y][i] && data[y][i] == ' ')
			i++;
		if (data[y][i] == '\0')
			continue ;
		if (ft_elems_ok(map))
			ft_get_map(map, data[y]);
		if (!map->om)
			ft_save_elems(map, &data[y][i]);
	}
	ft_free_split(data);
	if (!ft_elems_ok(map))
		return (ft_error_int("Error while parsing elements of map", 1));
	return (0);
}