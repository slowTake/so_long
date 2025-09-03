/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 16:37:02 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
