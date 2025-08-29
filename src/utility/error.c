/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:05:21 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 09:08:13 by pnurmi           ###   ########.fr       */
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
	ft_putstr_fd("Invalid Map\n", 2);
	free(mapfile);
	exit(1);
}