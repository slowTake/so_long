/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:02:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/28 16:11:04 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(char *mapfile)
{
	if (count_objects(mapfile, 'P') != 1)
	{
		error_object(mapfile, "Player count");
	}
	if (count_objects(mapfile, 'C') <= 0)
	{
		error_object(mapfile, "Collectibles count");
	}
	if (count_objects(mapfile, 'E') != 1)
	{
		error_object(mapfile, "Exit count");
	}
	else
		ft_putstr_fd("Valid Map\n", 2);
}

int	count_objects(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}

// int	flood_fill_collectibles(char **mapfile, t_point size);

/*flood fill to see if all collectibles are reachable
start from the player
check if exit also reachable
flood fill needs the collectible count beforehand
checks if all collectibles are reachable by comparing

*/
