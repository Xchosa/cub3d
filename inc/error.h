/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:33 by mimalek           #+#    #+#             */
/*   Updated: 2025/09/29 17:28:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef	enum e_error
{
	ARGUMENT_AMOUNT = 1,
	WRONG_FILE_TYPE = 2,
	OPEN_FAILED		= 3,
	MALLOC_FAIL		= 4,
	CONFIGUARTION_LINE = 5,
	CONFIG_DUPLICATE = 6,
	IMAGE_OPEN_FAILED = 7,
	WRONG_COLOR_VALUE = 8,
	MLX_IMG_FAIL	= 9,
	MLX_INIT_FAIL	= 10,
	MLX_IMG_TO_WINDOW_FAIL = 11,
	MULTIPLE_PLAYER = 12,
	INVALID_MAP_CHARACTER = 13,
	EMPTY_LINE = 14,
	MAP_NOT_ENCLOSED = 15,
	NO_PLAYER = 16,

}				t_error;

void	ft_error( int error_code );
void	ft_error_msg( int error_code, char *msg );

void	ft_exit(int error_code);

void	cleanup_cub3d(t_cub3d *cub3d);

#endif
