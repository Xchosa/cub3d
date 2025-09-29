/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:08:58 by poverbec          #+#    #+#             */
/*   Updated: 2025/09/29 11:29:21 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map_file(char *map_path, int fd)
{
	char	*line;
	char	*content;
	char	*tmp;
	char	**map_array;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	tmp = NULL;
	(void)tmp;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &line);
		if (!line)
			break ;
		tmp = content;
		content = ft_strjoin(content, line);
		free(line);
		free(content);
	}
	close(fd);
	map_array = ft_split(content, '\n');
	return (free(content), map_array);
}

bool	space_map_check(int i, int j, char **map)
{
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
		map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (false);
	return (true);
}


int	return_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

bool	ft_is_map_enclosed(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = return_map_height(map);
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
				if (space_map_check(i, j, map) == false)
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
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

