/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/02 15:57:25 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 119)
		printf("Moving up!\n");
	if (keycode == 115)
		printf("Moving down!\n");
	if (keycode == 100)
		printf("Moving right!\n");
	if (keycode == 97)
		printf("Moving left!\n");
	return (0);
}

int	move_up(t_game *game, int x, int y)
{
	int	collectibles;

	if (game->map[y + 1][x] == '1')
		return (0);
	if (game->map[y + 1][x] == 'E')
		if (collectibles = 0)
			return (1);
	// check collectibles
	if (game->map[y + 1][x] == '0')
		game_player_position(game, x + 1, y);
	if (game->map[y + 1][x] == 'C')
		collectibles--;
	return (1);
}

int	move_down(t_game *game, int x, int y)
{
	int	collectibles;

	if (game->map[y - 1][x] == '1')
		return (0);
	else if (game->map[y - 1][x] == 'E')
		if (collectibles = 0)
			return (1);
	// check collectibles
	game_player_position(game, x - 1, y);
	return ;
}
int	move_right(t_game *game, int x, int y)
{
	int	collectibles;

	if (game->map[y][x + 1] == '1')
		return (0);
	if (game->map[y][x + 1] == 'E')
		if (collectibles = 0)
			return (1);
	// check collectibles
	game_player_position(game, x, y + 1);
	return ;
}

int	move_left(t_game *game, int x, int y)
{
	int	collectibles;

	// add collectibles counter or function
	if (game->map[y][x - 1] == '1')
		return (0);
	if (game->map[y][x - 1] == 'E')
		if (collectibles = 0)
			return (1);
	// check collectibles
	game_player_position(game, x, y - 1);
	return (1);
}
