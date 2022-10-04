/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:41:14 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 15:06:19 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 1024

/*
 * === ft_bzero === *
 */

void	ft_bzero(char *str, int x);

/*
 * === ft_str === *
 */

int		ft_strlen(char *s);
char	*ft_strcopy(char *src, char dst[BUFFER_SIZE]);

#endif