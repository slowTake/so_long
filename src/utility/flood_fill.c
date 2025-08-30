/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:31:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/30 16:11:54 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodfill(t_map_info *info, int x, int y)
{
	if (x < 0 || x >= info->cols || y < 0 || y >= info->rows)
		return (0);
	if (info->visited[y][x] == 1 || info->visited[y][x] == '1')
		return (0);
	info->visited[y][x] = 1;
	floodfill(info, x + 1, y);
	floodfill(info, x - 1, y);
	floodfill(info, x, y + 1);
	floodfill(info, x, y - 1);
	return (1);
}

int	flood_find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	**create_visited_array(int height, int width)
{
}

void	free_visited_array(int **visited, int height);
// {
// 	free(visited);
// }
