/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_assets.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:17:31 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 09:37:00 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ASSETS_H
# define GAME_ASSETS_H

typedef struct s_textures
{
	void		*player;
	void		*wall;
	void		*floor;
	void		*collectible;
	void		*exit;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	textures;
	char		**map;
	int			player_x;
	int			player_y;
	int			collectible;
	int			map_width;
	int			map_height;
	int			move_count;
}				t_game;

#endif
