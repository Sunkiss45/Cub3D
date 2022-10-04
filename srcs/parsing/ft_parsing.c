/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 15:50:03 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
