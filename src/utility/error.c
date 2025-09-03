/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:05:21 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/03 16:26:45 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_object(char *mapfile, char *error_msg)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error_msg, 2);
	free(mapfile);
	exit(1);
}

void	error_map(char *mapfile)
{
	ft_putstr_fd("Error\n", 2);
	free(mapfile);
	exit(1);
}

void	error_free_game(char *mapfile, char *error_msg, t_game *game)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error_msg, 2);
	free(game);
	free(mapfile);
	exit(1);
}

void	error_exit(t_game *game, char *message)
{
	if (message)
		ft_putstr_fd(message, 2);
	if (game)
		cleanup_game(game);
	exit(1);
}
