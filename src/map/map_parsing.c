/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:14:31 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 16:14:35 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game, char *filename)
{
	game->collectible = 0;
	read_and_split_map(game, filename);
	get_map_dimensions(game);
	check_walls(game);
	find_player(game);
	count_collectibles(game);
	validate_map_path(game);
}

void	read_and_split_map(t_game *game, char *filename)
{
	char	*map_contents;

	parse_arg(filename);
	map_contents = read_map(filename);
	if (!map_contents)
		error_exit(game, "Error:\nCould not read map file.\n");
	check_map_tile(map_contents);
	check_objects(game, map_contents);
	game->map = ft_split(map_contents, '\n');
	free(map_contents);
	if (!game->map)
		error_exit(game, "Error:\nMap split failed.\n");
}

char	*read_map(char *filename)
{
	int		fd;
	char	*map_whole;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(NULL, "Error:\nCouldn't open map\n");
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		error_exit(NULL, "Error:\nMap is empty\n");
	}
	map_whole = ft_strdup(line);
	if (!map_whole)
	{
		free(line);
		return (NULL);
	}
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		map_whole = ft_strjoin_and_free(map_whole, line);
		if (!map_whole)
		{
			free(line);
			return (NULL);
		}
	}
	close(fd);
	return (map_whole);
}

char	*ft_strjoin_and_free(char *map_whole, char *line)
{
	char	*result;

	result = ft_strjoin(map_whole, line);
	if (map_whole)
		free(map_whole);
	if (line)
		free(line);
	return (result);
}
