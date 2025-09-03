/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:06:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 18:02:41 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *game)
{
	int	i;

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
	exit(0);
}

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	cleanup_game(game);
	exit(0);
}

void	cleanup_visited_array(t_map_info *info)
{
	int	i;

	i = 0;
	while (i < info->rows)
	{
		free(info->visited[i]);
		i++;
	}
	free(info->visited);
}
