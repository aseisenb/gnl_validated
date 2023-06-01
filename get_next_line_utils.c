/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:34:15 by aseisenb          #+#    #+#             */
/*   Updated: 2022/07/20 14:53:30 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	if (!s2[0])
		return (s1);
	if (ft_strchr(s2) > 0)
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strchr(s2) + 1));
	else
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1 && s1[len1])
		s3[len1++] = s1[len2++];
	len2 = 0;
	while (s2[len2] && s2[len2] != '\n')
		s3[len1++] = s2[len2++];
	if (s2[len2] == '\n')
		s3[len1++] = s2[len2];
	s3[len1] = 0;
	free(s1);
	return (s3);
}
