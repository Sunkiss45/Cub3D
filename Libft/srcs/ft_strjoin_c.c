/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:56:06 by ebarguil          #+#    #+#             */
/*   Updated: 2022/10/29 17:43:21 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_c(char *s1, char *s2, char c)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = c;
	new[i + j + 1] = '\0';
	return (new);
}
