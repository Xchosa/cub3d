


#include "cub3d.h"
#include "parse.h"


int	argument_check(int argc, char **argv)
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
