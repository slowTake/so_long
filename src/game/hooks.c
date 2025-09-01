/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/01 12:28:26 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307) // ESC key
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 119) // W key
		printf("Moving up!\n");
	if (keycode == 97) // A key
		printf("Moving left!\n");
	if (keycode == 115) // S key
		printf("Moving down!\n");
	if (keycode == 100) // D key
		printf("Moving right!\n");
	return (0);
}

int	load_textures(t_game *game)
{
	int width, height;
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/player.xpm", &width, &height);
	if (!game->textures.player)
		return (0);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/wall.xpm", &width, &height);
	if (!game->textures.wall)
		return (0);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/floor.xpm", &width, &height);
	if (!game->textures.floor)
		return (0);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/coins.xpm", &width, &height);
	if (!game->textures.collectible)
		return (0);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/door.xpm", &width, &height);
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
	switch (tile)
	{
	case '1':
		sprite = game->textures.wall;
		break ;
	case 'P':
		sprite = game->textures.player;
		break ;
	case 'C':
		sprite = game->textures.collectible;
		break ;
	case 'E':
		sprite = game->textures.exit;
		break ;
	case '0':
	default:
		return ; // Just floor, already drawn
	}
	if (sprite)
		mlx_put_image_to_window(game->mlx, game->win, sprite, x * 32, y * 32);
}

void	render_map(t_game *game)
{
	int x, y;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
