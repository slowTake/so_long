/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 13:49:13 by pnurmi           ###   ########.fr       */
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
		move_up(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 100)
		move_right(game);
	if (keycode == 97)
		move_left(game);
	return (0);
}

int	move_up(t_game *game)
{
	int	next_y;
	int	next_x;

	next_y = game->player_y - 1;
	next_x = game->player_x;
	if (game->map[next_y][next_x] == '1')
		return (0);
	if (game->map[next_y][next_x] == 'E')
	{
		if (game->collectible == 0)
			exit_game(game);
		return (0);
	}
	if (game->map[next_y][next_x] == 'C')
		game->collectible--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = next_y;
	game->map[game->player_y][game->player_x] = 'P';
	render_map(game);
	return (1);
}

int	move_down(t_game *game)
{
	int	next_y;
	int	next_x;

	next_y = game->player_y + 1;
	next_x = game->player_x;
	if (game->map[next_y][next_x] == '1')
		return (0);
	if (game->map[next_y][next_x] == 'E')
	{
		if (game->collectible == 0)
			exit_game(game);
		return (0);
	}
	if (game->map[next_y][next_x] == 'C')
		game->collectible--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = next_y;
	game->map[game->player_y][game->player_x] = 'P';
	render_map(game);
	return (1);
}

int	move_right(t_game *game)
{
	int	next_y;
	int	next_x;

	next_y = game->player_y;
	next_x = game->player_x + 1;
	if (game->map[next_y][next_x] == '1')
		return (0);
	if (game->map[next_y][next_x] == 'E')
	{
		if (game->collectible == 0)
			exit_game(game);
		return (0);
	}
	if (game->map[next_y][next_x] == 'C')
		game->collectible--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = next_x;
	game->map[game->player_y][game->player_x] = 'P';
	render_map(game);
	return (1);
}

int	move_left(t_game *game)
{
	int	next_y;
	int	next_x;

	next_y = game->player_y;
	next_x = game->player_x - 1;
	if (game->map[next_y][next_x] == '1')
		return (0);
	if (game->map[next_y][next_x] == 'E')
	{
		if (game->collectible == 0)
			exit_game(game);
		return (0);
	}
	if (game->map[next_y][next_x] == 'C')
		game->collectible--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = next_x;
	game->map[game->player_y][game->player_x] = 'P';
	render_map(game);
	return (1);
}
