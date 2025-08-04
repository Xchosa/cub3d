/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/08/04 10:49:26 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"


// load path
bool	parse_map_file(t_cub3d *cub3d, char *map_path, int fd )
{
	if(ft_validate_parse_file(cub3d, fd) == false)
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


