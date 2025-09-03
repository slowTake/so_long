/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:15:05 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 14:48:18 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "flood_fill.h"
# include "game_assets.h"
# include "libft.h"
# include "minilibx/mlx.h"

// Meeps
void	parse_map(t_game *game, char *filename);
char	*read_map(char *filename);
void	print_map(char *map);
int		count_objects(char *map, char c);
void	check_objects(char *mapfile);
void	check_map_boundaries(char *map);
void	line_validation(char *map);
int		map_width(char *map);
int		map_height(char *map);
void	map_floodfill_validation(char *map);

// error
void	error_object(char *mapfile, char *error_msg);
void	check_map_tile(char *map);
void	error_map(char *mapfile);
void	error_exit(void);
void	error_free_game(char *mapfile, char *error_msg, t_game *game);

// pasing
void	parse_arg(char *argv);

// flood fill
int		floodfill(t_map_info *info, int x, int y);
int	flood_find_player(char **map, int *x, int *y); //<<<<<<<<<<<delete
int		**create_visited_array(int rows, int cols);

// game

int		load_textures(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
void	render_map(t_game *game);
void	texture_cleanup(t_game *game);
void	execute_game(char *argv);
void	find_player(t_game *game);
void	exit_game(t_game *game);

// tracking
void	game_player_position(t_game *game, int x, int y);
void	count_collectibles(t_game *game);

// movement
int		key_hook(int keycode, t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

#endif