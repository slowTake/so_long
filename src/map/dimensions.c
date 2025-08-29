/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:13:16 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 14:30:58 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(char *map)
{
	int	width;

	width = 0;
	while (map[width] != '\n')
	{
		width++;
	}
	return (width);
}

int	map_height(char *map)
{
	int height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}