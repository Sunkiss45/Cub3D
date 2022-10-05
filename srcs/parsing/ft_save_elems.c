/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:48:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/05 18:57:19 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_calc_data(char *l, char one, char two)
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
	// int	fd;
	int	i;

	if (!x)
		return ;
	i = x;
	while (l[i] && l[i] != ' ')
		i++;
	ft_strcopy_n(&l[x], tex, i - x);
	// fd = open(tex, O_RDONLY);
	// if (fd < 0)
	// {
	// 	ft_bzero(tex, BUFFER_SIZE);
	// 	return ;
	// }
	// close(fd);
	return ;
}

void	ft_save_elems(t_map *map, char *l)
{
	ft_save_this_tex(l, ft_calc_data(l, 'N', 'O'), map->tex_no);
	ft_save_this_tex(l, ft_calc_data(l, 'S', 'O'), map->tex_so);
	ft_save_this_tex(l, ft_calc_data(l, 'W', 'E'), map->tex_we);
	ft_save_this_tex(l, ft_calc_data(l, 'E', 'A'), map->tex_ea);
	return ;
}
