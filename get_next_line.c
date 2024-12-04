/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-mah <mben-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:06:32 by mben-mah          #+#    #+#             */
/*   Updated: 2024/12/04 20:28:06 by mben-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_store(int fd, char **stash)
{
	char		*buffer;
	ssize_t		read_bytes;
	char		*temp;

	buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(*stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
		{
			free(*stash);
			free(buffer);
			return (NULL);
		}
		free(*stash);
		*stash = temp;
	}
	free(buffer);
	return (*stash);
}

static char	*get_line(char *stash)
{
	size_t		i;
	char		*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	size_t		i;
	char		*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_store(fd, &stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}
