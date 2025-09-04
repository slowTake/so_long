/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:02:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 15:21:21 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_objects(t_game *game, char *mapfile)
{
	if (count_objects(mapfile, 'P') != 1)
	{
		free(mapfile);
		error_exit(game, "Error:\nInvalid player count\n");
	}
	if (count_objects(mapfile, 'C') <= 0)
	{
		free(mapfile);
		error_exit(game, "Error:\nNo collectibles found\n");
	}
	if (count_objects(mapfile, 'E') != 1)
	{
		free(mapfile);
		error_exit(game, "Error:\nInvalid exit count\n");
	}
}

int	count_objects(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	check_map_tile(char *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		error_map(map);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'E' && map[i] != 'C'
			&& map[i] != 'P' && map[i] != '\n')
		{
			error_map(map);
		}
		i++;
	}
}

int	get_map_dimensions(t_game *game)
{
	game->map_height = 0;
	if (!game->map)
		return (0);
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	return (1);
}

void	validate_map_path(t_game *game)
{
	t_map_info	info;

	initialize_floodfill(game, &info);
	floodfill(&info, game->player_x, game->player_y);
	check_unreachable(game, &info);
	cleanup_visited_array(&info);
}
