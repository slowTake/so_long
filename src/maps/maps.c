/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:14:31 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/28 16:01:35 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	parse_map(char *filename)
{
	char	*map_contents;

	map_contents = ft_strdup("");
	map_contents = read_map(filename);
	map_check(map_contents);
}

char	*read_map(char *filename)
{
	int		fd;
	char	*map_whole;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_whole = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(map_whole, line);
		free(map_whole);
		free(line);
		if (!temp)
		{
			close(fd);
			return (NULL);
		}
		map_whole = temp;
	}
	close(fd);
	return (map_whole);
}
