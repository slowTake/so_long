/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:38:25 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/30 13:05:11 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_map_info
{
	char	**map;
	int		**visited;
	int		rows;
	int		cols;
}			t_map_info;

#endif