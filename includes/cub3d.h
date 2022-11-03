/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:57:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/11/03 04:01:17 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ft_color.h"
# include "../Libft/includes/libft.h"

typedef struct s_map
{
	char	*name;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	char	**om;
	int		*map;
	bool	map_ok;
	int		sizeline;
	int		nbline;
	int		flo;
	int		cel;
	int		fd;
}	t_map;

/*
 * === ft_error === *
 */

int		ft_error_int(char *e, int x);
int		ft_warning_int(char *w, char *l, int x);

/*
 * === parsing === *
 */

int		ft_check_name(t_map *map);
int		ft_fill_col(char *l, int end, int r, int i);
bool	ft_isdigit_cub(char *s, int n);
int		ft_parsing(t_map *map, char *str);
int		ft_read_data(t_map *map, char **data);
void	ft_save_elems(t_map *map, char *l);
int		ft_save_map(t_map *map);
bool	ft_verify_close_map(t_map *map);

#endif