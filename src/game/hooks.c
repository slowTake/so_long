/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:33:39 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 15:53:06 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119)
	{
		if (move_up(game) == 1)
			move_counter(game);
	}
	if (keycode == 115)
	{
		if (move_down(game) == 1)
			move_counter(game);
	}
	if (keycode == 100)
	{
		if (move_right(game) == 1)
			move_counter(game);
	}
	if (keycode == 97)
	{
		if (move_left(game) == 1)
			move_counter(game);
	}
	return (0);
}

void	move_counter(t_game *game)
{
	game->move_count++;
	printf("Moves: %d\n", game->move_count);
}

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
