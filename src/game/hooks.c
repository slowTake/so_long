/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/02 13:50:35 by pnurmi           ###   ########.fr       */
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

// void	move_up(t_game *game)
// {

// }

// void	move_down(t_game *game)
// {
// }
// void	move_right(t_game *game)
// {
// }

// void	move_left(t_game *game)
// {
// }
