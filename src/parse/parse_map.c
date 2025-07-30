#include "cub3d.h"
#include "parse.h"



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


// bool    parse_texture()
// {
//     t_strnstr(lines[i], "NO ", 3) 

// }