
#ifndef INIT_H
# define INIT_H


# include <stdbool.h>
# include "MLX42.h"
# include "libft.h"

# include <math.h>

# include <stdio.h>
# include <stdlib.h>
//minimap
//COLORS
# define WHITE_COLOR 0xFFFFFFFF
# define GREY_COLOR 0x555555FF
# define BLACK_COLOR 0x000000FF
# define PLAYER_COLOR 0x1E90FFFF
# define YELLOW_COLOR 0xFFFF00FF

//MAP
# define MINIMAP_WIDTH 260
# define MINIMAP_HEIGHT 152
# define MINIMAP_VIEW_SIZE 3
# define TILE_SIZE 32 // eine kachel 32 lange 32 breite 

//PLAYER
# define PLAYER_SIZE 10
# define PLAYER_SPEED 150.0
// halbes Pi in einer sekunde 90 grad
# define PLAYER_ROT_SPEED 1.57079632679
# define DIR_LINE_COLOR 0x0000FF

//SETTINGS
# define MIN_WINDOW_WIDTH 640
# define MIN_WINDOW_HEIGHT 480
# define MAX_WINDOW_WIDTH -1
# define MAX_WINDOW_HEIGHT -1
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define GRAPHICS_LENGTH 6

#endif

// minimap anfangen erstllen
// raycasting 