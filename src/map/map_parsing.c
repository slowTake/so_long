/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:14:31 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/02 13:57:32 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	parse_map(t_game *game, char *filename)
{
	char	*map_contents;

	// int		width;
	// int		height;
	parse_arg(filename);
	map_contents = read_map(filename);
	check_map_tile(map_contents);
	game->map = ft_split(map_contents, '\n');
	print_map(map_contents); // remove after
	//	width = map_width(map_contents);
	//	height = map_height(map_contents);
	check_objects(map_contents);
	free(map_contents);
}

char	*read_map(char *filename)
{
	int		fd;
	char	*map_whole;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit();
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

char	*read_map_line(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
	}
	close(fd);
	return (line);
}
