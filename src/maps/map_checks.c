/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:02:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/28 12:54:47 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(const char *mapfile)
{
	if (count_objects(mapfile, 'P') != 1)
		ft_putstr_fd("error player count\n", 2);
	if (count_objects(mapfile, 'C') <= 0)
		ft_putstr_fd("error collectibles\n", 2);
	if (count_objects(mapfile, 'E') != 1)
		ft_putstr_fd("error exits\n", 2);
	else
		ft_putstr_fd("Valid Map\n", 2);
}

int	count_objects(const char *map, char c)
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
