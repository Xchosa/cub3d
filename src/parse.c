/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:21 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/16 17:44:17 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_validate_parse_file(t_cub3d *data, int fd)
{
	char	*line;
	int		i = 0;

	(void)data;
	line = NULL;
	while (get_next_line(fd, &line) != NULL)
		ft_printf("%d: %s\n", i++, line);
	return (0);
}
