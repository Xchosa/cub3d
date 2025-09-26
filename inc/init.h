
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

# define movement_speed 50.0
# define rotation_speed 90.0
# define half_circle 1.57079
//MAP
# define MINIMAP_WIDTH 350
# define MINIMAP_HEIGHT 210
# define MINIMAP_VIEW_SIZE 3
# define CUBE_SIZE 32 // eine kachel 32 lange 32 breite
# define MINIMAP_CELL_GAP 2

//Rays
# define step_size 1;
# define FOV 60.0 // Field of view in degrees
# define NUM_RAYS 60 // Number of rays to cast
# define RAY_COLOR 0xFF00FFFF // Magenta color for rays
# define RAY_LENGTH 200 // Maximum ray length in pixels

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


typedef	struct s_player
{
	double		px_x;// use double or unit32_t
	double		px_y;// use double 
	double		direction; // Richtiung in die der Player schaut;
	char		player_view;
	double		time;


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
	char	**map_grid;
	int     map_height;
    int     map_width;
    int     square_size;
	int		player_pos_x;
	int		player_pos_y; // start position 
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
	int			show_minimap;
	int			show_rays;


}	t_cub3d;

typedef struct	s_ray
{
	// Ray direction and position
	double	ray_angle;		// Aktueller ray angle
	double	ray_x;			// Ray start X position
	double	ray_y;			// Ray start Y position
	double	delta_x;		// Wie viel andert sich der X-Wert bei einem Schritt nach vorne
	double	delta_y;		// Wie viel andert sich der Y-Wert bei einem Schritt nach vorne

	// DDA algorithm variables
	int		map_x;			//  In Welcher Grid Zelle wir aktuell sind (X-Wert)
	int		map_y;			// Aktuelle Grid Zelle (Y-Wert)
	double	side_dist_x;	// Distanz von der Ray position zur nachsten vertikalen Grid Line
	double	side_dist_y;	// Distanz von der Ray position zu nachsten horizontalen Grid Line
	double	delta_dist_x;	// Distanz zwischen Grid Lines (vertikal)
	double	delta_dist_y;	// Distanz zwischen Grid Line (horizontal)
	int		step_x;			// Step Richtung X (-1 (links) or 1 (rechts))
	int		step_y;			// Step Richtung Y (-1 (hoch) or 1 (runter))

	// Hit information
	int		hit;			// Wurde wall gehitted?
	int		side;			// Welche wall wurd gehitted?
	double	wall_dist;		// Distanz zur wall
	char	wall_type;		// Welcher Character wurde gehitted ('1', '0')

	// Projection calculation
	int		line_height;	// Hohe der Wall Line
	int		draw_start;		// Start Y Koordinate fur die Projektion
	int		draw_end;		// Ende Y Koordinate fur die Projektion

}	t_ray;





bool			init_cub3d(t_cub3d *cub3d, char *map_path, int fd);
double			x_array_texture(t_ray *ray);
bool			init_textures(t_cub3d *cub3d);
bool			load_texture(t_cub3d *cub3d);
mlx_texture_t	*load_wall_texture(t_cub3d *cub3d, t_ray *ray);
bool			fill_mlx_textures(t_cub3d *cub3d);
void			set_up_cub3d_defaults(t_cub3d *cub3d);
uint32_t		r_ceil(t_cub3d *cub3d);

bool			create_mlx(t_cub3d *cub3d);

t_graphics		*get_map(t_graphics *graphics, char **argv);



// hook function for escape and player movement
void			game_loop(void *param);
void			draw_map_background(t_cub3d *cub3d);
void			render_map(t_cub3d *cub3d);
void			draw_map_background(t_cub3d *cub3d);
void			draw_minimap_background(t_cub3d *cub3d, int start_x,
					int start_y);
void			draw_minimap_cells(t_cub3d *cub3d, int minimap_x,
					int minimap_y);
int				get_cell_color(char cell);
void			replace_spaces_with_2(char **map);

// minimap
bool			init_minimap(t_cub3d *cub3d);
bool			map_to_grid(t_cub3d *cub3d);
bool			malloc_minimap_grid(t_cub3d *cub3d);
int				return_square_size(t_cub3d *cub3d, int map_width,
					int map_height);
void			draw_minimap(t_cub3d *cub3d);
int				get_map_height(char **map);
int				get_map_width(char **map);
void			draw_square(t_cub3d *cub3d, uint32_t color, int start_x,
					int start_y);
void			init_player(t_cub3d *cub3d);
void			player_view_direction(t_cub3d *cub3d, double y, double x);
void			draw_player_minimap(t_cub3d *cub3d, double y, double x);
void			set_player_view(t_cub3d *cub3d, char player_direction);
bool			parse_map_file(t_cub3d *cub3d, char *map_path, int fd);

// game loop 
void			game_loop(void *param);
void			rotate_player(t_cub3d *cub3d, double angle_change);
void			handle_toggles(t_cub3d *cub3d);
void			cast_single_ray(t_cub3d *cub3d, double angle);
void			draw_single_ray(t_cub3d *cub3d, double ray_x, double ray_y);
bool			boundary_and_wall_collision_check(t_cub3d *cub3d, int grid_x,
					int grid_y);

void			update_y_and_x(t_cub3d *cub3d, double px_d, double py_d);
//bool		check_for_wall(t_cub3d *cub3d);
bool			check_wall_rotate(t_cub3d *cub3d,  double px_d,
					double py_d, double fps);
bool			check_vertical_wall_hit(t_cub3d *cub3d, t_ray *ray);
void			rotate_player_keys(t_cub3d *cub3d, double fps);
bool			ft_validate_parse_file(t_cub3d *data, int fd);
int				argument_check(int argc, char **argv);
void			ft_parse_texture(char *path, t_img *texture);
char			**read_map_file(char *map_path, int fd);
bool			ft_is_map_enclosed(char **map);
int				get_max_width(char **map);
char			*pad_line(char *line, int width);
char			**pad_map(char **map);
bool			ft_validate_map(char **map);
bool			is_walkable(char c);


void			print_array(char **array);
void    		cast_rays(t_cub3d *cub3d);
double  		get_player_angle(char direction);
void   			render_frame(t_cub3d *cub3d);
void    		init_ray(t_cub3d *cub3d, t_ray *ray, int x);




void	perform_dda(t_cub3d *cub3d, t_ray *ray);
void	calculation_projection(t_cub3d *cub3d, t_ray *ray);
void	draw_column(t_cub3d *cub3d, t_ray *ray, int x);
#endif

