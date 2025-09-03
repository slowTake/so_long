/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:31:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 17:15:38 by pnurmi           ###   ########.fr       */
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

char	**create_map_copy(t_game *game)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(game->map_height * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
			{
				free(map_copy[i - 1]);
				i--;
			}
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

// void	free_visited_array(int **visited, int height);
// {
// 	int i
// }