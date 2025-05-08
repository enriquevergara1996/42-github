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
			free(storage);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage || ft_strchr(storage, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
}

static char	*extract_newline(char *storage)
{
	char	*line;
	char	*newline;
	size_t	line_len;

	if (storage && *storage == '\n')
	{
		line = malloc(2);
		if (!line)
			return (NULL);
		line[0] = '\n';
		line[1] = '\0';
		return (line);
	}
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

char	*extract_line(char *storage)
{
	char	*line;

	line = extract_newline(storage);
	if (line)
		return (line);
	if (storage && *storage)
		return (ft_strdup(storage));
	return (NULL);
}

char	*update_storage(char *storage)
{
	char	*newline;
	char	*new_storage;
	size_t	line_len;

	if (storage && *storage == '\n')
	{
		new_storage = ft_strdup(storage + 1);
		free(storage);
		return (new_storage);
	}
	newline = ft_strchr(storage, '\n');
	if (newline)
	{
		line_len = newline - storage + 1;
		new_storage = ft_strdup(storage + line_len);
		free(storage);
		return (new_storage);
	}
	free(storage);
	return (NULL);
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
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = update_storage(storage);
	return (line);
}
