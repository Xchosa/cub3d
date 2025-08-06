/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:08:58 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/06 10:40:59 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "parse.h"

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
	free(content);
	return (map_array);
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
