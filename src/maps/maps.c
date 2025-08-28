/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:14:31 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/28 10:02:30 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	gnl_map(void)
{
	char	*map;
	int		fd;

	fd = open("test_map.ber", O_RDONLY);
	while ((map = get_next_line(fd)) != NULL)
	{
		// ft_printf("%s", map);
		map_parse(map);
		// printf("%d", map_parse(map));
		free(map);
		// check ecp
		// strchr
		// strlen?
	}
	close(fd);
}

void	map_parse(const char *map)
{
	if (count_players(map) != 1)
		ft_putstr_fd("error\n", 2);
	if (count_collectibles(map) >= 1)
		ft_putstr_fd("error\n", 2);
	if (count_exits(map) != 1)
		ft_putstr_fd("error\n", 2);
	ft_putstr_fd("Valid Map\n", 2);
}

int	count_players(const char *map)
{
	int	i;
	int	players;

	i = 0;
	players = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			players++;
		i++;
	}
	return (players);
}

int	count_collectibles(const char *map)
{
	int	i;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			collectibles++;
		i++;
	}
	return (collectibles);
}
int	count_exits(const char *map)
{
	int i;
	int exits;

	i = 0;
	exits = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			exits++;
		i++;
	}
	return (exits);
}