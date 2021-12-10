/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:47:25 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/04 00:05:12 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_null(char	**ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*parse_line(char	**reminder)
{
	char	*line;
	char	*end;
	char	*temp;

	end = ft_strchr(*reminder, '\n');
	if (!**reminder)
	{
		free_null(reminder);
		return (NULL);
	}
	if (end)
	{
		line = ft_substr(*reminder, 0, (end - *reminder) + 1);
		temp = *reminder;
		*reminder = ft_strdup(end + 1);
		free_null(&temp);
	}
	else
	{
		line = ft_strdup(*reminder);
		free_null(reminder);
	}
	return (line);
}

static char	*get_all(int fd, char *buffer, char **reminder, int bytes_to_read)
{	
	int		bytes_read;
	char	*swapper;

	bytes_read = 1;
	while (!(ft_strchr(*reminder, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, bytes_to_read);
		if (bytes_read == -1)
		{
			free_null(&buffer);
			free_null(reminder);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		swapper = *reminder;
		*reminder = ft_strjoin(swapper, buffer);
		free_null(&swapper);
	}
	free_null(&buffer);
	return (*reminder);
}

char	*get_next_line(int fd, int bytes_to_read)
{
	static char		*reminder[MAX_FD];
	char			*actual_line;
	char			*buffer;

	if (fd < 0 || bytes_to_read <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = (char *)malloc((bytes_to_read + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!reminder[fd])
		reminder[fd] = ft_strdup("");
	reminder[fd] = get_all(fd, buffer, &reminder[fd], bytes_to_read);
	if (!reminder[fd])
		return (NULL);
	actual_line = parse_line(&reminder[fd]);
	return (actual_line);
}
