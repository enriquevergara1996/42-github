/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:56:58 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 13:56:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	char	*newline;
	size_t	line_len;

	newline = ft_strchr(storage, '\n');
	if (newline)
	{
		line_len = newline - storage + 1;
		line = malloc(line_len + 1);
		if (!line)
			return (NULL);
		ft_memcpy(line, storage, line_len);
		line[line_len] = '\0';
		return (line);
	}
	return (NULL);
}

char	*update_storage(char *storage)
{
	char	*newline;
	char	*new_storage;
	size_t	line_len;

	newline = ft_strchr(storage, '\n');
	if (newline)
	{
		line_len = newline - storage + 1;
		new_storage = ft_strdup(storage + line_len);
		free(storage);
		return (new_storage);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		if (!storage || *storage == '\0')
		{
			free(storage);
			storage = NULL;
			return (NULL);
		}
		line = ft_strdup(storage);
		free(storage);
		storage = NULL;
	}
	else
		storage = update_storage(storage);
	return (line);
}
