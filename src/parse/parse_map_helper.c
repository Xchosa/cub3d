/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:08:58 by poverbec          #+#    #+#             */
/*   Updated: 2025/07/31 10:08:59 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "parse.h"


char	**read_map_file(char *map_path)
{
	int		fd;
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
