/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:11:24 by mimalek           #+#    #+#             */
/*   Updated: 2025/08/06 10:24:41 by poverbec         ###   ########.fr       */
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


typedef struct s_object
{
	char	**map;
	int     map_height;
    int     map_width;
    int     square_size;
}	t_object;


t_object	*get_object(void);
bool        init_object(t_cub3d *cub3d);

#endif
