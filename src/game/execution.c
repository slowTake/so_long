/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:41:57 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 15:43:25 by pnurmi           ###   ########.fr       */
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
		error_exit();
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	exit_game(&game);
}

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	texture_cleanup(game);
	exit(0);
}
