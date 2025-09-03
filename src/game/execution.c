/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:41:57 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 19:10:29 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	execute_game(char *argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	parse_map(&game, argv);
	if (!load_textures(&game))
		error_exit(&game, "Error");
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	error_exit(&game, "");
}
