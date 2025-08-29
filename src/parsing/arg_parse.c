/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:23:37 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/29 12:10:39 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_arg(char *argv)
{
	char	*filename;
	char	*extension;
	char	*result;

	filename = argv;
	extension = ".ber";
	result = ft_strnstr(filename, extension, ft_strlen(filename));
	if (result == NULL)
		error_exit();
}

// addition check if map exists