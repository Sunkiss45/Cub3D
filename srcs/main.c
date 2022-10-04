/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:56:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 16:07:15 by ebarguil         ###   ########.fr       */
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
