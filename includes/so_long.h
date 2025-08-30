/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:15:05 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/30 16:11:38 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "flood_fill.h"
# include "libft.h"

// Meeps
void	parse_map(char *filename);
char	*read_map(char *filename);
void	print_map(char *map);

// map check
int		count_objects(char *map, char c);
void	check_objects(char *mapfile);
void	check_map_boundaries(char *map);
void	line_validation(char *map);

// error
void	error_object(char *mapfile, char *error_msg);
void	check_map_tile(char *map);
void	error_map(char *mapfile);
void	error_exit(void);

// dimensions
int		map_width(char *map);
int		map_height(char *map);
void	map_floodfill_validation(char *map);

// pasing
void	parse_arg(char *argv);

// flood fill
int		floodfill(t_map_info *info, int x, int y);
int		flood_find_player(char **map, int *x, int *y);
int		**create_visited_array(int height, int width);
void	free_visited_array(int **visited, int rows);

#endif