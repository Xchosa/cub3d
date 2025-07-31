/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:09:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/07/31 10:54:27 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"


// load path 
bool	parse_map_file(t_cub3d *cub3d, char *map_path)
{
    char    **lines;

    (void)cub3d;
    // 2D array getrennt bei \n 
    lines = read_map_file(map_path);
    if (!lines)
        return (false);
    
    // parse_textures( )

    return (true);
}


