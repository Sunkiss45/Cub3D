/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:56:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 15:46:05 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_int(char *e, int x)
{
	write(2, BRED" ! ", ft_strlen(BRED) + 3);
	write(2, e, ft_strlen(e));
	write(2, " !" RESET "\n", ft_strlen(RESET) + 3);
	return (x);
}

int	ft_check_name(t_map *map)
{
	int	i;

	if (ft_strlen(map->name) < 4)
		return (ft_error_int("map name is too short to be valid", 1));
	i = ft_strlen(map->name);
	if (map->name[--i] != 'b' || map->name[--i] != 'u'
		|| map->name[--i] != 'c' || map->name[--i] != '.')
		return (ft_error_int("map name not ending by \".cub\"", 1));
	map->fd = open(map->name, O_DIRECTORY);
	if (map->fd > 0)
	{
		close(map->fd);
		return (ft_error_int("map name is a Directory", 1));
	}
	map->fd = open(map->name, O_RDONLY);
	if (map->fd < 0)
		return (ft_error_int("map name doesn't exist", 1));
	return (0);
}

int	ft_parsing(t_map *map, char *str)
{
	ft_strcopy(str, map->name);
	if (!map->name[0])
		return (ft_error_int("argument is invalid (too long or NULL)", 1));
	if (ft_check_name(map))
		return (1);
	close(map->fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	ac--;
	if (ac != 1)
		return (ft_error_int("Too few/many argument(s)", 1));
	if (ft_parsing(&map, av[1]))
		return (1);
	printf(GREEN"[%s] / [%s]"RESET"\n", av[1], map.name);
	return (0);
}
