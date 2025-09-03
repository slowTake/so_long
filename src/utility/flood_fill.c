/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:31:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 18:18:57 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_map_info *info, int x, int y)
{
	if (x < 0 || x >= info->cols || y < 0 || y >= info->rows)
		return ;
	if (info->map[y][x] == '1')
		return ;
	if (info->visited[y][x] == 1)
		return ;
	info->visited[y][x] = 1;
	floodfill(info, x + 1, y);
	floodfill(info, x - 1, y);
	floodfill(info, x, y + 1);
	floodfill(info, x, y - 1);
}

void	initialize_floodfill(t_game *game, t_map_info *info)
{
	get_map_dimensions(game);
	info->map = game->map;
	info->rows = game->map_height;
	info->cols = game->map_width;
	info->visited = create_visited_array(info->rows, info->cols);
	if (!info->visited)
		error_exit(game, "Error: Visited array creation failed.\n");
}

void	check_unreachable(t_game *game, t_map_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->rows)
	{
		x = 0;
		while (x < info->cols)
		{
			if ((info->map[y][x] == 'C' || info->map[y][x] == 'E')
				&& info->visited[y][x] == 0)
			{
				cleanup_visited_array(info);
				error_exit(game, "Error: Unreachable collectible or exit.\n");
			}
			x++;
		}
		y++;
	}
}

int	**create_visited_array(int rows, int cols)
{
	int	i;
	int	j;
	int	**visited;

	i = 0;
	visited = malloc(rows * sizeof(int *));
	if (!visited)
		return (NULL);
	while (i < rows)
	{
		visited[i] = malloc(cols * sizeof(int));
		if (!visited[i])
		{
			j = 0;
			while (j < i)
			{
				free(visited[j]);
				j++;
			}
			free(visited);
			return (NULL);
		}
		j = 0;
		while (j < cols)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}
