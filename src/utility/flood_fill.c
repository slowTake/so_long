/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:31:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 13:47:22 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	flood_fill(char **map, int visited, int x, int y, int width, int height)
{
	width = map_width(map);
	height = map_height(map);
	if (visited == 0)
	{
	}
}

// int	flood_fill_collectibles(char **mapfile, t_point size);

/*flood fill to see if all collectibles are reachable
start from the player
check if exit also reachable
flood fill needs the collectible count beforehand
checks if all collectibles are reachable by comparing

*/
/*int	main(void)
{
	t_map	map;
}

int	flood_fill(t_map *map)
{
	int tmp_width = map->width;
	char **tmp_map_coords = map->coordinates;
}*/