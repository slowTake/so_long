/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/01 09:55:11 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307) // ESC key
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 119) // W key
		printf("Moving up!\n");
	if (keycode == 97) // A key
		printf("Moving left!\n");
	if (keycode == 115) // S key
		printf("Moving down!\n");
	if (keycode == 100) // D key
		printf("Moving right!\n");
	return (0);
}
