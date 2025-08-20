/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:42:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/20 09:49:53 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_buffer(char *read_buff, int fd, char **line)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, read_buff, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (0);
	}
	if (bytes_read == 0)
	{
		if (*line && (*line)[0] == '\0')
		{
			free(*line);
			*line = NULL;
		}
		return (0);
	}
	read_buff[bytes_read] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	read_buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (1)
	{
		if (read_buff[0] == '\0')
		{
			if (!ft_read_buffer(read_buff, fd, &line))
				return (line);
		}
		line = ft_extract_line(read_buff, line);
		if (!line)
			return (NULL);
		if (ft_check_nl(line, '\n') != -1)
		{
			return (line);
		}
	}
}

char	*ft_extract_line(char *read_buff, char *line)
{
	char	*joined;
	int		new_pos;

	new_pos = ft_check_nl(read_buff, '\n');
	if (new_pos == -1)
	{
		joined = ft_strjoin(line, read_buff);
		free(line);
		if (!joined)
			return (NULL);
		read_buff[0] = '\0';
		return (joined);
	}
	return (ft_handle_newline(read_buff, new_pos, line));
}

void	ft_shift_buffer(char *read_buff, size_t start)
{
	size_t	i;

	i = 0;
	while (start <= BUFFER_SIZE && read_buff[start])
	{
		read_buff[i] = read_buff[start];
		i++;
		start++;
	}
	while (i <= BUFFER_SIZE)
	{
		read_buff[i] = '\0';
		i++;
	}
}

char	*ft_handle_newline(char *read_buff, int new_pos, char *line)
{
	char	*temp;
	char	*joined;

	temp = ft_substr(read_buff, 0, new_pos + 1);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	joined = ft_strjoin(line, temp);
	free(temp);
	free(line);
	if (!joined)
		return (NULL);
	ft_shift_buffer(read_buff, new_pos + 1);
	return (joined);
}
