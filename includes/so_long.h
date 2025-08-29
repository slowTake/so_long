/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:15:05 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 11:44:06 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

// Meeps
void	parse_map(char *filename);
char	*read_map(char *filename);
void	print_map(char *map);

// map check
int		count_objects(char *map, char c);
void	check_objects(char *mapfile);
void	check_map_boundaries(char *map);

// error
void	error_object(char *mapfile, char *error_msg);
void	check_map_tile(char *map);
void	error_map(char *mapfile);
void	error_exit(void);

// utility
int		map_width(char *map);
int		map_height(char *map);

// pasing
void	parse_arg(char *argv);

#endif