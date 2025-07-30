#include "cub3d.h"
#include "parse.h"



bool	parse_map_file(t_cub3d *cub3d, char *map_path)
{
    char    **line;

    line = read_map_file(map_path);
    if (!line)
        return (false);
    
    

    return (true);
}