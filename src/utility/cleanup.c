/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:06:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 19:07:44 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	texture_cleanup(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

void	exit_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
}

void	cleanup_visited_array(t_map_info *info)
{
	int	i;

	if (!info || !info->visited)
		return ;
	i = 0;
	while (i < info->rows && info->visited[i])
	{
		free(info->visited[i]);
		i++;
	}
	free(info->visited);
	info->visited = NULL;
}
