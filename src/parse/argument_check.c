/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:17 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/06 14:55:25 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// print map 
bool	parse_map_file(t_cub3d *cub3d, char *map_path, int fd )
{
	if (ft_validate_parse_file(cub3d, fd) == false)
		return (false);
	print_array(cub3d->map);
	if (ft_validate_map(cub3d->map, map_path) == false)
		return (false);
	return (true);
}

int	argument_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_error(ARGUMENT_AMOUNT), -1);
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		return (ft_error(WRONG_FILE_TYPE), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_FAILED), -1);
	return (fd);
}
