/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:02:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/27 09:42:50 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *mapfile)
{
	/*check existence of map file
	check if something is mapfile
	check wall around map
	check player only 1 not more
	check collectible
	check if collectible is reachable
	check exit, invalid if more than 1
	check dimensions both size should be equal to each other
	*/
}

int	flood_fill_collectibles(char **mapfile, t_point size)
{
}
/*flood fill to see if all collectibles are reachable
start from the player
check if exit also reachable
flood fill needs the collectible count beforehand
checks if all collectibles are reachable by comparing

*/
