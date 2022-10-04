/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:57:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 15:38:38 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ft_color.h"
# include "../Libft/includes/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	name[BUFFER_SIZE];
	int		fd;
}	t_map;

#endif