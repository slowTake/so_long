/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:13:16 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 11:18:48 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(char *map)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (map[i] != '\n')
	{
		i++;
		width++;
	}
	return (width);
}

int	map_height(char *map)
{
	int i = 0;
	int height = 1;

	while (map[i])
	{
		if (map[i] == '\n' || map[i] == '\0')
			height++;
		i++;
	}
	return (height);
}