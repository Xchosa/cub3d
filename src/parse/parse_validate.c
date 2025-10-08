/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:15:56 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/08 11:08:57 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_validate_parse_file(t_cub3d *cub3d, int fd)
{
	char	*line;
	int		config_arg;
	int		error;

	config_arg = 0;
	if (allocate_cub3d_map(cub3d) == false)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (config_arg == 6)
		{
			if(ft_parse_map(cub3d, line) == false)
			{
				printf("wrong exit");
				return(false);
			}
		
		}
		else
		{
			error = ft_parse_config_line(cub3d, line);
			if (error == -1)
				return (free(line), false);
			config_arg += error;
		}
		handle_line(line);
	}
	return (true);
}

bool	allocate_cub3d_map(t_cub3d *cub3d)
{
	cub3d->map = malloc(sizeof(char *) * (MAX_MAP_SIZE + 1));
	if (!cub3d->map)
		return (ft_error(MALLOC_FAIL), false);
	ft_memset(cub3d->map, 0, sizeof(char *) * (MAX_MAP_SIZE + 1));
	return (true);
}

void	handle_line(char *line)
{
	if (line != NULL || !line)
		free(line);
	line = NULL;
}