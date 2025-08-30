/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:13:16 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/30 16:07:33 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(char *map)
{
	int	width;

	if (!map)
		error_exit();
	width = 0;
	while (map[width] != '\n' && map[width])
	{
		width++;
	}
	return (width);
}

int	map_height(char *map)
{
	int	height;
	int	i;

	i = 0;
	if (!map)
		error_exit();
	height = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	if (i > 0 && map[i - 1] != '\n')
		height++;
	return (height);
}

void	map_floodfill_visited(char *map)
{
	char	**map_2d;
	int		**visited;
	int		width;
	int		height;

	width = map_width(map);
	height = map_height(map);
	visited = create_visited_array(height, width);
	map_2d = ft_split(map, '\n');
	// flood_fill();
	// free_visited_array(map_2d, height);
}

// validation needs to happen after all objects are verified