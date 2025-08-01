/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:35:40 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/24 12:15:07 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error( int error_code )
{
	if (error_code == 1)
		ft_error_msg(error_code, "Wrong Amount of Arguments");
	else if (error_code == 2)
		ft_error_msg(error_code, "Wrong File Type");
	else if (error_code == 3)
		ft_error_msg(error_code, "Unable to Open File");
	else if (error_code == 4)
		ft_error_msg(error_code, "Malloc Failed");
	else if (error_code == 5)
		ft_error_msg(error_code, "Configuration Line Error");
	else if (error_code == 6)
		ft_error_msg(error_code, "Configuration Duplicate Error");
	else if (error_code == 7)
		ft_error_msg(error_code, "Image Open Failed");
	else if (error_code == 8)
		ft_error_msg(error_code, "Wrong Colour Value");
	else if (error_code == 9)
		ft_error_msg(error_code, "MLX Image Load failed");
	else if (error_code == 10)
		ft_error_msg(error_code, "Initialising MLX failed");
	else if (error_code == 11)
		ft_error_msg(error_code, "Loading IMG to Window failed");
	else
		ft_error_msg(error_code, "Unknown Error");
}

void	ft_error_msg( int error_code, char *msg )
{
	ft_printf("-------------------------\n");
	ft_printf("Error: %d\n", error_code);
	ft_printf("%s\n", msg);
	ft_printf("-------------------------\n");
	ft_exit(error_code);
}
