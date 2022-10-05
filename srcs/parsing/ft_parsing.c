/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/05 17:36:56 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_infos_ok(t_map *map)
{
	if (!map->tex_no[0])
		return (false);
	if (!map->tex_so[0])
		return (false);
	if (!map->tex_we[0])
		return (false);
	if (!map->tex_ea[0])
		return (false);
	return (true);
}

int	ft_calc_tex(char *l, char one, char two)
{
	int	i;
	int	y;
	int	ret;

	i = 0;
	y = i + 1;
	ret = 0;
	if (l[i] && l[y] && (l[i] == one && l[y] == ' '))
		ret = 1;
	else if (l[i] && l[y] && l[y + 1]
		&& (l[i] == one && l[y] == two && l[y + 1] == ' '))
		ret = 2;
	while (ret > 0 && l[ret] == ' ')
		ret++;
	return (ret);
}

void	ft_save_this_tex(char *l, int x, char tex[BUFFER_SIZE])
{
	int	i;

	if (!x)
		return ;
	i = x;
	while (l[i] && l[i] != ' ')
		i++;
	ft_strcopy_n(&l[x], tex, i - x);
}

void	ft_save_infos(t_map *map, char *l)
{
	ft_save_this_tex(l, ft_calc_tex(l, 'N', 'O'), map->tex_no);
	ft_save_this_tex(l, ft_calc_tex(l, 'S', 'O'), map->tex_so);
	ft_save_this_tex(l, ft_calc_tex(l, 'W', 'E'), map->tex_we);
	ft_save_this_tex(l, ft_calc_tex(l, 'E', 'A'), map->tex_ea);
	return ;
}

int	ft_check_infos(t_map *map)
{
	char	*l;
	int		i;

	l = gnl(map->fd);
	while (l)
	{
		printf(CYAN"[%s]"RESET"\n", l);
		i = 0;
		while (l[i] && l[i] == ' ')
			i++;
		if (l[i] == '\n' || ft_infos_ok(map))
		{
			free(l);
			l = gnl(map->fd);
			continue ;
		}
		ft_save_infos(map, &l[i]);
		free(l);
		l = gnl(map->fd);
	}
	return (0);
}

void	ft_init_map(t_map *map, char *str)
{
	ft_strcopy(str, map->name);
	map->tex_no[0] = '\0';
	map->tex_so[0] = '\0';
	map->tex_we[0] = '\0';
	map->tex_ea[0] = '\0';
	map->fd = 0;
}

int	ft_parsing(t_map *map, char *str)
{
	ft_init_map(map, str);
	if (!map->name[0])
		return (ft_error_int("argument is invalid (too long or NULL)", 1));
	if (ft_check_name(map))
		return (1);
	if (ft_check_infos(map))
		return (1);
	close(map->fd);
	return (0);
}
