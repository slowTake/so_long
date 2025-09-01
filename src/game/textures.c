/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:28:49 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/01 16:41:37 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	int width, height;
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &width, &height);
	if (!game->textures.player)
		return (0);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&width, &height);
	if (!game->textures.wall)
		return (0);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
			&width, &height);
	if (!game->textures.floor)
		return (0);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"sprites/coins.xpm", &width, &height);
	if (!game->textures.collectible)
		return (0);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "sprites/door.xpm",
			&width, &height);
	if (!game->textures.exit)
		return (0);
	return (1);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	void	*sprite;

	sprite = NULL;
	mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 32,
		y * 32);
	if (tile == '1')
		sprite = game->textures.wall;
	else if (tile == 'P')
		sprite = game->textures.player;
	else if (tile == 'C')
		sprite = game->textures.collectible;
	else if (tile == 'E')
		sprite = game->textures.exit;
	else
		return ;
	if (sprite)
		mlx_put_image_to_window(game->mlx, game->win, sprite, x * 32, y * 32);
}
void	render_map(t_game *game)
{
	int x, y;
	y = 0;
	if (!game || !game->map)
	{
		ft_printf("error map\n");
		return ;
	}
	while (game->map[y])
	{
		x = 0;
		if (!game->map[y])
		{
			ft_printf("error\n");
			error_exit();
		}
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
