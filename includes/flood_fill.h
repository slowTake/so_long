/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:38:25 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 13:56:01 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_map
{
	int		width;
	int		height;
	int		visited;
	int		x;
	int		y;
	char	**coordinates;
}			t_map;

#endif