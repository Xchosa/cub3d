/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:11:24 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/16 17:24:45 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

# include "libft.h"
# include "MLX42.h"
# include "init.h"
# include "error.h"
# include "parse.h"


void	ft_exit(int error_code);

bool	parse_map_file(t_cub3d *cub3d, char *map_path);

void	game_loop(void *param);
void	cleanup_cub3d(t_cub3d *cub3d);


#endif
