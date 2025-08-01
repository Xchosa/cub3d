/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:21 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/31 15:42:21 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	ft_parse_config_line(t_cub3d *data, char *line);
static void	ft_parse_color(char *line, int **color);


bool	ft_validate_parse_file(t_cub3d *cub3d, int fd)
{
	char	*line;
	int		i;
	int		check_config;
	int		config_arg;

	(void)check_config;
	(void)i;
	line = NULL;
	i = 0;
	check_config = -1;
	config_arg = 0;
	cub3d->graphics = malloc(sizeof(t_graphics));
	if (!cub3d->graphics)
		ft_error(MALLOC_FAIL);
	while (get_next_line(fd, &line) != NULL)
	{
		ft_printf("line: %s\n", line);
		config_arg += ft_parse_config_line(cub3d, line);
	}
	if (config_arg != 6)
	{
		ft_error(CONFIG_DUPLICATE);
		free(line);
		return (false);
	}
	if(load_texture(cub3d) == false)
		return (false);
	return (true);
}


// try t_strnstr(lines[i], "NO ", 3)
static int	ft_parse_config_line(t_cub3d *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' ||
		line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
		i++;
	if (line[i] == 'N' && line[i + 1] && line[i + 2] && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (ft_parse_texture(line + i + 3, &data->graphics->north), 1);
	else if (line[i] == 'S' && line[i + 1] && line[i + 2] && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (ft_parse_texture(line + i + 3, &data->graphics->south), 1);
	else if (line[i] == 'W' && line[i + 1] && line[i + 2] && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (ft_parse_texture(line + i + 3, &data->graphics->west), 1);
	else if (line[i] == 'E' && line[i + 1] && line[i + 2] && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (ft_parse_texture(line + i + 3, &data->graphics->east), 1);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		return (ft_parse_color(line + i + 2, &data->graphics->floor_colour), 1);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (ft_parse_color(line + i + 2, &data->graphics->ceiling_colour), 1);
	return (0);
}




static void	ft_parse_color(char *line, int **color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		ft_error(CONFIGUARTION_LINE);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error(WRONG_COLOR_VALUE);
	*color = malloc(sizeof(int) * 3);
	if (!*color)
		ft_error(MALLOC_FAIL);
	(*color)[0] = r;
	(*color)[1] = g;
	(*color)[2] = b;
}


