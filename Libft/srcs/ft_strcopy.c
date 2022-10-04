/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:30:36 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/04 14:50:39 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcopy(char *src, char dst[BUFFER_SIZE])
{
	int		i;

	ft_bzero(dst, BUFFER_SIZE);
	if (!src || ft_strlen(src) > BUFFER_SIZE - 1)
		return (dst);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	return (dst);
}
