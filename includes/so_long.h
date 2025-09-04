/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:15:05 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 17:16:59 by pnurmi           ###   ########.fr       */
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
int		count_objects(char *map, char c);
void	check_objects(t_game *game, char *mapfile);
int		get_map_dimensions(t_game *game);
void	check_walls(t_game *game);

// error
void	check_map_tile(char *map);
void	error_map(char *mapfile);
void	error_free_game(char *mapfile, char *error_msg, t_game *game);
void	error_exit(t_game *game, char *message);

// parsing
void	parse_arg(char *argv);
void	read_and_split_map(t_game *game, char *filename);
char	*ft_strjoin_and_free(char *map_whole, char *line);
char	*read_map(char *filename);

// flood fill
void	floodfill(t_map_info *info, int x, int y);
void	validate_map_path(t_game *game);
void	initialize_floodfill(t_game *game, t_map_info *info);
void	check_unreachable(t_game *game, t_map_info *info);
int		**create_visited_array(int rows, int cols);

// game
int		load_textures(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
void	render_map(t_game *game);
void	execute_game(char *argv);
void	find_player(t_game *game);
void	exit_game(t_game *game);
int		close_window(t_game *game);

// tracking
void	count_collectibles(t_game *game);
void	move_counter(t_game *game);

// movement
int		key_hook(int keycode, t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

// cleanup
void	cleanup_game(t_game *game);
void	texture_cleanup(t_game *game);
void	exit_game(t_game *game);
void	cleanup_visited_array(t_map_info *info);
char	*close_and_return_null(int fd);

#endif