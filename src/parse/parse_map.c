/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/28 10:07:36 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

bool	ft_has_valid_characters(char **map);
bool	ft_has_single_player(char **map);
bool	ft_no_empty_lines(char **map);

bool	ft_validate_map(char **map)
{
	char	**padded_map;

	padded_map = pad_map(map);
	if (!padded_map)
		ft_error(MALLOC_FAIL);
	if (!ft_has_valid_characters(map))
		ft_error(INVALID_MAP_CHARACTER);
	if (!ft_has_single_player(map))
		ft_error(MULTIPLE_PLAYER);
	if (!ft_is_map_enclosed(padded_map))
		ft_error(MAP_NOT_ENCLOSED);
	if (!ft_no_empty_lines(map))
		ft_error(EMPTY_LINE);
	return (true);
}

bool	ft_has_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01NSEW ", map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_has_single_player(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player_count++;
				if (player_count > 1)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

// Only player and floor are walkable
bool	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
