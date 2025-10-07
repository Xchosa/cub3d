/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:21 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/07 10:16:10 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_for_whitespaces(char *line, int i)
{
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
	{
		i++;
	}
	return (i);
}

// try t_strnstr(lines[i], "NO ", 3)
// parse texture returned kein true or false 
// parse color retured kein true or false 
int	ft_parse_config_line(t_cub3d *cub3d, char *line)
{
	int	i;
	int	error_code;

	i = 0;
	i = check_for_whitespaces(line, i);
	error_code = parse_texture_helper(cub3d, line, i);
	if (error_code != 0)
		return (error_code);
	else if (line[i] == 'E' && line[i + 1] && line[i + 2] && line[i + 1]
		== 'A' && line[i + 2] == ' ')
	{
		if (!ft_parse_texture(line + i + 3, &cub3d->graphics->east))
			return (-1);
		return (1);
	}
	else if (line[i] == 'F' && line[i + 1] == ' ')
	{
		if (!ft_parse_color(line + i + 2, &cub3d->graphics->floor_colour))
			return (-1);
		return (1);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		if (!ft_parse_color(line + i + 2, &cub3d->graphics->ceiling_colour))
			return (-1);
		return (1);
	}
	else if (line[i] == '\0' || line[i] == '\n')
		return (0);
	return (ft_error(CONFIGUARTION_LINE), -1);
}

bool	ft_parse_color(char *line, int **color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if ((void *)color[0] != 0)
		return (ft_error(CONFIG_DUPLICATE), false);
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		ft_error(CONFIGUARTION_LINE);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_array(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_error(WRONG_COLOR_VALUE), false);
	*color = malloc(sizeof(int) * 3);
	if (!*color)
		return (ft_error(MALLOC_FAIL), false);
	(*color)[0] = r;
	(*color)[1] = g;
	(*color)[2] = b;
	return (true);
}
// return reinbauen  fuer error 
// zu bool umbauen 

//if (line == NULL || !line)
//		return ;
void	ft_parse_map(t_cub3d *cub3d, char *line)
{
	static int	i = 0;
	char		*trimmed_line;

	if (i >= MAX_MAP_SIZE)
		ft_error(ARGUMENT_AMOUNT);
	if (line == NULL || !line)
		return ;
	trimmed_line = ft_strtrim(line, "\t\n\v\f\r ");
	if (!trimmed_line || trimmed_line[0] == '\0')
	{
		free(trimmed_line);
		return ;
	}
	cub3d->map[i] = ft_strdup(trimmed_line);
	free(trimmed_line);
	if (!cub3d->map[i])
		ft_error(MALLOC_FAIL);
	i++;
}
