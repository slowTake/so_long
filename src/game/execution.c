/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:41:57 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/02 15:37:30 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	execute_game(char *argv)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	parse_map(&game, argv);
	if (!load_textures(&game))
	{
		ft_printf("Error textures\n");
		error_exit();
	}
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
}

// int	game_collectibles(int collectibles)
// {
// }

void	game_player_position(t_game *game, int x, int y)
{
}
