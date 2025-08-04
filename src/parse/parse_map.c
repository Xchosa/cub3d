/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/04 14:12:18 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

bool	ft_validate_map(char **map);

// load path
bool	parse_map_file(t_cub3d *cub3d, char *map_path, int fd )
{
	if(ft_validate_parse_file(cub3d, fd) == false)
		return (false);
	if (ft_validate_map(cub3d->map) == false)
		return (false);
    // 2D array getrennt bei \n
	// point fd schon nur noch auf die map?
	// printf( "before: %s\n", lines[0]);
    // lines = read_map_file(map_path , fd);
    // if (!lines)
    //     return (false);
	(void)map_path;
    return (true);
}

bool	ft_validate_map(char **map)
{
	int	i;
	int	j;
	bool	has_player;
	bool	first_line;

	has_player = false;
	first_line = true;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (has_player)
					ft_error(MULTIPLE_PLAYER);
				has_player = true;
			}
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
				ft_error(INVALID_MAP_CHARACTER);
			j++;
		}
		i++;
	}
	return (true);
}


