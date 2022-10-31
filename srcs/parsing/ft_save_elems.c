/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:48:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/31 02:01:24 by ebarguil         ###   ########.fr       */
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

int	ft_save_this_tex(char *l, int x, char **tex)
{
	// int	fd;
	int	i;

	if (!x)
		return (0);
	i = x;
	while (l[i] && l[i] != ' ')
		i++;
	*tex = ft_strdup_n(&l[x], i - x);
	if (!*tex)
		return (2);
	// fd = open(tex, O_RDONLY);
	// if (fd < 0)
	// {
	// 	ft_bzero(tex, BUFFER_SIZE);
	// 	return (0);
	// }
	// close(fd);
	return (1);
}

int	ft_save_this_col(char *l, int x, int *color)
{
	int		i;

	if (!x)
		return (0);
	i = x;
	while (l[i] && l[i] != ' ')
		i++;
	if (ft_contains(&l[x], ',') != 2 || l[x] == ',' || l[i - 1] == ','
		|| i - x > 11 || i - x < 5 || !ft_isdigit_cub(&l[x], i - x))
		return (0);
	*color = ft_fill_col(&l[x - 1], i, -1, -1);
	return (1);
}

void	ft_save_elems(t_map *map, char *l)
{
	int	r;

	r = 0;
	r += ft_save_this_tex(l, ft_calc_data(l, 'N', 'O'), &map->tex_no);
	r += ft_save_this_tex(l, ft_calc_data(l, 'S', 'O'), &map->tex_so);
	r += ft_save_this_tex(l, ft_calc_data(l, 'W', 'E'), &map->tex_we);
	r += ft_save_this_tex(l, ft_calc_data(l, 'E', 'A'), &map->tex_ea);
	r += ft_save_this_col(l, ft_calc_data(l, 'F', ' '), &map->flo);
	r += ft_save_this_col(l, ft_calc_data(l, 'C', ' '), &map->cel);
	if (!r)
		ft_warning_int("This line was ignored on .cub :", l, 1);
	else if (r == 2)
		ft_warning_int("Exeption malloc (ft_save_this_col) :", l, 1);
	return ;
}
