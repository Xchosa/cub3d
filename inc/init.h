
#ifndef INIT_H
# define INIT_H

# include "MLX42.h"

//minimap
//COLORS
# define WHITE_COLOR 0xFFFFFFFF
# define GREY_COLOR 0x555555FF
# define BLACK_COLOR 0x000000FF
# define BLACK_TRANS_COLOR 0x00000080
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

// cell_type minimap
// # define WALL 1
// # define BACKGROUND 3

typedef	struct s_player
{
	int		px_x;
	int		px_y;
	double	direction; // Richtiung in die der Player schaut;
 // square_size / player pos
} t_player ;

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


typedef struct s_minimap
{
	char	**map;
	int     map_height;
    int     map_width;
    int     square_size;
	int		player_pos_x;
	int		player_pos_y; //inex
	// minimap_img_width 
	
}	t_minimap;

// img struct
// 

typedef struct s_cub3d
{
	mlx_t		*mlx;
	int			fd;
	mlx_image_t	*img;
	t_graphics	*graphics;
	char		**map; // raus nur in minimap;
	uint32_t	window_width;
	uint32_t	window_height;
	uint32_t	minimap_img_width;
	uint32_t	minimap_img_height;
	t_minimap	minimap;
	t_player	player;


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
void		draw_minimap_background(t_cub3d *cub3d, int start_x, int start_y);
void		draw_minimap_cells(t_cub3d *cub3d, int minimap_x, int minimap_y);
int			get_cell_color(char cell);


// minimap
bool		init_minimap(t_cub3d *cub3d);
int			return_square_size(t_cub3d *cub3d, int map_width, int map_height);
void		draw_minimap(t_cub3d *cub3d);
int			get_map_height(char **map);
int			get_map_width(char **map);
void		draw_square(t_cub3d *cub3d, uint32_t color, int start_x,
				int start_y);
void		init_player(t_cub3d *cub3d);
void		player_view_direction(t_cub3d *cub3d, int y, int x);
void		draw_player_minimap(t_cub3d *cub3d, int y, int x);


bool		parse_map_file(t_cub3d *cub3d, char *map_path, int fd);

void		game_loop(void *param);


bool		ft_validate_parse_file(t_cub3d *data, int fd);
int			argument_check(int argc, char **argv);
void		ft_parse_texture(char *path, t_img *texture);
char		**read_map_file(char *map_path, int fd);
bool		ft_is_map_enclosed(char **map);
int			get_max_width(char **map);
char		*pad_line(char *line, int width);
char		**pad_map(char **map);
bool		ft_validate_map(char **map);
bool		is_walkable(char c);

void	print_array(char **array);
#endif

// To do
// minimap anfangen erstllen
//
// raycasting
