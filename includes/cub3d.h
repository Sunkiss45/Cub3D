/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:57:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/06 20:27:19 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ft_color.h"
# include "../Libft/includes/libft.h"

typedef struct s_map
{
	char	name[BUFFER_SIZE];
	char	tex_no[BUFFER_SIZE];
	char	tex_so[BUFFER_SIZE];
	char	tex_we[BUFFER_SIZE];
	char	tex_ea[BUFFER_SIZE];
	int		flo;
	int		cel;
	int		fd;
}	t_map;

/*
 * === ft_error === *
 */

int		ft_error_int(char *e, int x);

/*
 * === parsing === *
 */

int		ft_check_elems(t_map *map);
int		ft_check_name(t_map *map);
bool	ft_isdigit_cub(char *s, int n);
int		ft_parsing(t_map *map, char *str);
void	ft_save_elems(t_map *map, char *l);

#endif