/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:15:42 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/29 17:43:10 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char c, char *set)
{
	int	i;

	i = -1;
	while (set && set[++i])
		if (set[i] == c)
			return (&set[i]);
	return (NULL);
}
