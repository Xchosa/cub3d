/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:35:40 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/06 14:23:48 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_2( int error_code );

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
		ft_error_2(error_code);
}

void	ft_error_2( int error_code )
{
	if (error_code == 12)
		ft_error_msg(error_code, "Multiple Players in Map");
	else if (error_code == 13)
		ft_error_msg(error_code, "Invalid Map Character");
	else if (error_code == 14)
		ft_error_msg(error_code, "Empty Line in Map");
	else if (error_code == 15)
		ft_error_msg(error_code, "Map Not Enclosed");
	else if (error_code == 16)
		ft_error_msg(error_code, "No Player existing in Map");
	else
		ft_error_msg(error_code, "Unknown Error");
}

void	ft_error_msg( int error_code, char *msg )
{
	ft_printf("-------------------------\n");
	ft_printf("Error: %d\n", error_code);
	ft_printf("%s\n", msg);
	ft_printf("-------------------------\n");
}
