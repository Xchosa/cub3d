/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:11:24 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/06 14:32:10 by poverbec         ###   ########.fr       */
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


void	move_player(t_cub3d *cub3d);
void	update_player_pos(t_cub3d *cub3d, double fps, double px_d, double py_d);

#endif
