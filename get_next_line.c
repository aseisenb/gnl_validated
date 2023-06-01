/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:10:01 by aseisenb          #+#    #+#             */
/*   Updated: 2022/07/27 16:30:56 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buffer_update(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strchr(buffer);
	if (j > 0)
	{
		while (buffer[j])
			buffer[i++] = buffer[j++];
	}
	buffer[i] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			byte_was_read;

	byte_was_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(line, buffer);
	while (byte_was_read > 0 && ft_strchr(line) == '\0')
	{
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_was_read < 0)
			return (free(line), NULL);
		buffer[byte_was_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	ft_buffer_update(buffer);
	return (line);
}
