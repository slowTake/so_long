/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:12:41 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/01 16:33:49 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	if (argc == 2)
	{
		parse_map(&game, argv[1]);
		if (!load_textures(&game))
		{
			ft_printf("Error textures\n");
			return (1);
		}
		render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_putstr_fd("Enter a valid map", 2);
	return (0);
}
