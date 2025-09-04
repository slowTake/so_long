/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:23:37 by pnurmi            #+#    #+#             */
/*   Updated: 2025/09/04 15:20:33 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_arg(char *argv)
{
	char	*filename;
	char	*extension;
	char	*result;
	int		fd;

	filename = argv;
	extension = ".ber";
	result = ft_strnstr(filename, extension, ft_strlen(filename));
	if (result == NULL)
		error_exit(NULL, "Error\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(NULL, "Error:\ncouldnt open map\n");
	close(fd);
}
