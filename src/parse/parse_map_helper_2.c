/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helper_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:03:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/08 11:31:57 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_width(char **map)
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

bool	check_map_size(int height, int width)
{
	if (height < 3 || width < 3)
		return (false);
	if (height > 120 || width > 165)
		return (false);
	return (true);
}

char	*pad_line(char *line, int width)
{
	char	*new_line;
	int		i;

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

void	free_new_map(char **new_map, int i)
{
	while (i-- > 0)
		free(new_map[i - 1]);
	free(new_map);
	return ;
}

char	**pad_map(char **map)
{
	int		height;
	int		width;
	char	**new_map;
	int		i;

	i = 0;
	height = return_map_height(map);
	width = get_max_width(map);
	if (check_map_size(height, width) == false)
		return (NULL);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	while (i < height)
	{
		new_map[i] = pad_line(map[i], width);
		if (!new_map[i])
		{
			return (free_new_map(new_map, i), NULL);
		}
		i++;
	}
	new_map[height] = NULL;
	return (new_map);
}
