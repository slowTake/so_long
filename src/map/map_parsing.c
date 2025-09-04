/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:14:31 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 12:22:44 by pnurmi           ###   ########.fr       */
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
		error_exit(game, "Error: Could not read map file.\n");
	check_map_tile(map_contents);
	check_objects(game, map_contents);
	game->map = ft_split(map_contents, '\n');
	free(map_contents);
	if (!game->map)
		error_exit(game, "Error: Map split failed.\n");
}

char	*read_map(char *filename)
{
	int		fd;
	char	*map_whole;
	char	*line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(NULL, "Error: couldnt open map");
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
