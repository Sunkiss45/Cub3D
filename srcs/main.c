/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:56:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/31 00:48:38 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error_int(char *e, int x)
{
	write(2, BRED"\nERROR :\n ! ", ft_strlen(BRED) + 12);
	write(2, e, ft_strlen(e));
	write(2, " !" RESET "\n\n", ft_strlen(RESET) + 4);
	return (x);
}

int	ft_warning_int(char *w, char *l, int x)
{
	write(2, BORANGE"\nWARNING :\n ! ", ft_strlen(BORANGE) + 12);
	write(2, w, ft_strlen(w));
	if (l)
	{
		write(2, "\n\t -> \"", 7);
		write(2, l, ft_strlen(l));
		write(2, "\"", 1);
	}
	write(2, RESET"\n\n", ft_strlen(RESET) + 2);
	return (x);
}

void	ft_free_pars(t_map *map)
{
	if (map->name)
		free (map->name);
	if (map->tex_no)
		free (map->tex_no);
	if (map->tex_so)
		free (map->tex_so);
	if (map->tex_we)
		free (map->tex_we);
	if (map->tex_ea)
		free (map->tex_ea);
	return ;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (BUFFER_SIZE != 1024)
		return (ft_error_int("libft.h => BUFFER_SIZE must be 1024", 1));
	ac--;
	if (ac != 1)
		return (ft_error_int("Too few/many argument(s)", 1));
	if (ft_parsing(&map, av[1]))
		return (ft_free_pars(&map), 1);
	printf(GREEN"av : [%s] / name : [%s]"RESET"\n", av[1], map.name);
	printf(GREEN"tex_no : [%s]"RESET"\n", map.tex_no);
	printf(GREEN"tex_so : [%s]"RESET"\n", map.tex_so);
	printf(GREEN"tex_we : [%s]"RESET"\n", map.tex_we);
	printf(GREEN"tex_ea : [%s]"RESET"\n", map.tex_ea);
	printf(GREEN"flo : [%i]"RESET"\n", map.flo);
	printf(GREEN"cel : [%i]"RESET"\n", map.cel);
	return (ft_free_pars(&map), 0);
}
