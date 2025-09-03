/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:02:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 14:47:55 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_objects(char *mapfile)
{
	if (count_objects(mapfile, 'P') != 1)
		error_object(mapfile, "Player count\n");
	if (count_objects(mapfile, 'C') <= 0)
		error_object(mapfile, "Collectibles count\n");
	if (count_objects(mapfile, 'E') != 1)
		error_object(mapfile, "Exit count\n");
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

void	check_map_tile(char *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		error_map(map);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'E' && map[i] != 'C'
			&& map[i] != 'P' && map[i] != '\n')
		{
			error_map(map);
		}
		i++;
	}
}

/*
REDUNDANT
*/
void	check_map_boundaries(char *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		error_map(map);
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			error_map(map);
		i++;
	}
}

void	print_map(char *map)
{
	int	i;

	i = 0;
	ft_printf("\n\n");
	while (map[i])
	{
		ft_printf("%c", map[i]);
		i++;
	}
	ft_printf("\n\n\n");
}
