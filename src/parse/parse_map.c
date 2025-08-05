/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/05 10:26:20 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

bool	ft_validate_map(char **map);
bool	ft_has_valid_characters(char **map);
bool	ft_has_single_player(char **map);
bool	ft_no_empty_lines(char **map);
bool	ft_is_map_enclosed(char **map);
int		get_max_width(char **map);
char	*pad_line(char *line, int width);
char	**pad_map(char **map);

// load path
bool	parse_map_file(t_cub3d *cub3d, char *map_path, int fd )
{
	if(ft_validate_parse_file(cub3d, fd) == false)
		return (false);
	print_array(cub3d->map);
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
	int i;
	int j;

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
	int i;
	int j;
	int player_count;

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

bool	ft_is_map_enclosed(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (is_walkable(map[i][j]))
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
					return (false);
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
					map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_no_empty_lines(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

int get_max_width(char **map)
{
	int	max;
	int	i;
	int	len;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

char	*pad_line(char *line, int width)
{
	char	*new_line;
	int	i;

	i = 0;
	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (NULL);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < width)
		new_line[i++] = ' ';
	new_line[i] = '\0';
	return (new_line);
}

char	**pad_map(char **map)
{
	int		height;
	int		width;
	char	**new_map;
	int	i;

	height = 0;
	width = get_max_width(map);
	i = 0;
	while (map[height])
		height++;
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	while (i < height)
	{
		new_map[i] = pad_line(map[i], width);
		if (!new_map[i])
		{
			while (i > 0)
			{
				free(new_map[i - 1]);
				i--;
			}
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[height] = NULL;
	return (new_map);
}


