
#ifndef INIT_H
# define INIT_H

# include "MLX42.h"

//minimap
//COLORS
# define WHITE_COLOR 0xFFFFFFFF
# define GREY_COLOR 0x555555FF
# define BLACK_COLOR 0x000000FF
# define PLAYER_COLOR 0x1E90FFFF
# define YELLOW_COLOR 0xFFFF00FF

//MAP
# define MINIMAP_WIDTH 260
# define MINIMAP_HEIGHT 150
# define MINIMAP_VIEW_SIZE 3
# define CUBE_SIZE 32 // eine kachel 32 lange 32 breite

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
# define MAX_MAP_SIZE 100


typedef struct s_img
{
	int				type; // player , walll etc
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	char			*path;
	bool			used;

}					t_img;

typedef struct s_graphics
{
	t_img			north;
	t_img			west;
	t_img			east;
	t_img			south;
	int				*floor_colour;
	int				*ceiling_colour;
}					t_graphics;

typedef struct s_cub3d
{
	mlx_t		*mlx;
	int			fd;
	mlx_image_t	*img;
	t_graphics	*graphics;
	char		**map;
	uint32_t	window_width;
	uint32_t	window_height;
	uint32_t	minimap_img_width;
	uint32_t	minimap_img_height;

}	t_cub3d;




bool		init_cub3d(t_cub3d *cub3d, char *map_path, int fd);

bool		init_textures(t_cub3d *cub3d);
bool		load_texture(t_cub3d *cub3d);
void		set_up_cub3d_defaults(t_cub3d *cub3d);

bool		create_mlx(t_cub3d *cub3d);

t_graphics	*get_map(t_graphics *graphics, char **argv);


// hook function for escape and player movement
void		game_loop(void *param);
void		draw_map_background(t_cub3d *cub3d);
void		render_map(t_cub3d *cub3d);
void		draw_map_background(t_cub3d *cub3d);

// minimap
void		draw_minimap(t_cub3d *cub3d);
int			get_map_height(char **map);
int			get_map_width(char **map);



bool		parse_map_file(t_cub3d *cub3d, char *map_path, int fd);

void		game_loop(void *param);


bool		ft_validate_parse_file(t_cub3d *data, int fd);
int			argument_check(int argc, char **argv);
void		ft_parse_texture(char *path, t_img *texture);
char		**read_map_file(char *map_path, int fd);

void	print_array(char **array);
#endif

// To do
// minimap anfangen erstllen
//
// raycasting
