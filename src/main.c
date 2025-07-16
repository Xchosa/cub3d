/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:14:43 by mimalek           #+#    #+#             */
/*   Updated: 2025/07/16 17:26:50 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	argument_check(int argc, char **argv);

int	main(int argc, char **argv)
{
	int	fd;
	t_cub3d	*data;

	data = malloc(sizeof(t_cub3d));
	if (!data)
		return(ft_error(MALLOC_FAIL), MALLOC_FAIL);
	fd = argument_check(argc, argv);
	ft_validate_parse_file(data, fd);
	return (close(fd), 0);
}

static int	argument_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_error(ARGUMENT_AMOUNT), -1);
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		return (ft_error(WRONG_FILE_TYPE), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(OPEN_FAILED), -1);
	return (fd);
}
