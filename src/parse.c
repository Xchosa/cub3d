/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:21 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/24 11:51:24 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	ft_parse_config_line(t_cub3d *data, char *line);
static void	ft_parse_texture(char *path, t_img *texture);

int	ft_validate_parse_file(t_cub3d *data, int fd)
{
	char	*line;
	int		i;
	int		check_config;
	int		config_arg;

	line = NULL;
	i = 0;
	check_config = -1;
	config_arg = 0;
	while (get_next_line(fd, &line) != NULL)
	{
		config_arg += ft_parse_config_line(data, line);
	}
	// if (config_arg < 6)
	// {
	// 	ft_error(CONFIGUARTION_LINE);
	// 	free(line);
	// 	return (-1);
	// }
	return (0);
}

static int	ft_parse_config_line(t_cub3d *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == 'N' && line[i + 1] && line[i + 2] && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (ft_parse_texture(line + i + 3, data->graphics->north), 1);
		else if (line[i] == 'S' && line[i + 1] && line[i + 2] && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (ft_parse_texture(line + i + 3, data->graphics->south), 1);
		else if (line[i] == 'W' && line[i + 1] && line[i + 2] && line[i + 1] == 'E' && line[i + 2] == ' ')
			return (ft_parse_texture(line + i + 3, data->graphics->west), 1);
		else if (line[i] == 'E' && line[i + 1] && line[i + 2] && line[i + 1] == 'A' && line[i + 2] == ' ')
			return (ft_parse_texture(line + i + 3, data->graphics->east), 1);
		// else if (line[i] == 'F' && line[i + 1] == ' ')
		// 	return (ft_parse_color(line + i + 2, &data->graphics->floor_colour), 1);
		// else if (line[i] == 'C' && line[i + 1] == ' ')
		// 	return (ft_parse_color(line + i + 2, &data->graphics->ceiling_colour), 1);
		else
			i++;
	}
	return (0);
}

static void	ft_parse_texture(char *path, t_img *texture)
{
	int	fd;

	if (!path || !*path)
		ft_error(CONFIGUARTION_LINE);
	while (path && (*path == ' ' || *path == '\t'))
		path++;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(IMAGE_OPEN_FAILED);
	close(fd);
	texture->path = ft_strdup(path);
	if (!texture->path)
		ft_error(MALLOC_FAIL);
	texture->img = NULL;
}


