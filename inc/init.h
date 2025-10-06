/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimalek <mimalek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:37:52 by mimalek           #+#    #+#             */
/*   Updated: 2025/10/06 14:44:02 by mimalek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "MLX42.h"

# define WHITE_COLOR 0xFFFFFFFF
# define GREY_COLOR 0x555555FF
# define BLACK_COLOR 0x000000FF
# define BLACK_TRANS_COLOR 0x00000080
# define PLAYER_COLOR 0x1E90FFFF
# define YELLOW_COLOR 0xFFFF00FF
# define MOVEMENT_SPEED 50.0
# define ROTATION_SPEED 90.0
# define HALF_CIRCLE 1.57079
# define MINIMAP_WIDTH 350
# define MINIMAP_HEIGHT 210
# define MINIMAP_VIEW_SIZE 3
# define CUBE_SIZE 32
# define MINIMAP_CELL_GAP 2
# define STEP_SIZE 1;
# define FOV 60.0
# define NUM_RAYS 60 
# define RAY_COLOR 0xFF00FFFF
# define RAY_LENGTH 200
# define PLAYER_SIZE 10
# define PLAYER_SPEED 150.0
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

typedef struct s_player
{
	double		px_x;
	double		px_y;
	double		direction;
	char		player_view;
	double		time;

}		t_player;

typedef struct s_img
{
	int				type;
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
	int		map_height;
	int		map_width;
	int		square_size;
	int		player_pos_x;
	int		player_pos_y;

}	t_minimap;

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
	t_minimap	minimap;
	t_player	player;
	int			show_minimap;
	int			show_rays;

}	t_cub3d;

typedef struct s_ray
{
	double	ray_angle;
	double	ray_x;
	double	ray_y;
	double	delta_x;
	double	delta_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_dist;
	char	wall_type;
	int		line_height;
	int		draw_start;
	int		draw_end;

}	t_ray;

bool			init_cub3d(t_cub3d *cub3d, char *map_path, int fd);
double			x_array_texture(t_ray *ray);
bool			init_textures(t_cub3d *cub3d);
bool			load_texture_2(t_cub3d *cub3d);
bool			load_texture(t_cub3d *cub3d);
mlx_texture_t	*load_wall_texture(t_cub3d *cub3d, t_ray *ray);
bool			fill_mlx_textures(t_cub3d *cub3d);
void			set_up_cub3d_defaults(t_cub3d *cub3d);
bool			create_mlx(t_cub3d *cub3d);
t_graphics		*get_map(t_graphics *graphics, char **argv);
void			draw_ceiling(t_cub3d *cub3d, t_ray *ray, int x);
void			draw_floor_pixel(t_cub3d *cub3d, int x, int start_y);
uint32_t		r_ceil(t_cub3d *cub3d);
uint32_t		r_floor(t_cub3d *cub3d);
uint32_t		get_texture_pixel(mlx_texture_t *texture, int tex_y,
					int text_x);
void			draw_wall_pixels(t_cub3d *cub3d, t_ray *ray,
					int x, mlx_texture_t *texture);
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
int				return_map_height(char **map);
void			ft_parse_map(t_cub3d *cub3d, char *line);
bool			ft_parse_color(char *line, int **color);
void			handle_line(char *line);
bool			allocate_cub3d_map(t_cub3d *cub3d);
bool			space_map_check(int i, int j, char **map);
int				ft_parse_config_line(t_cub3d *data, char *line);
bool			ft_has_valid_characters(char **map);
bool			ft_has_single_player(char **map);
bool			ft_no_empty_lines(char **map);
bool			check_for_player(char **map);
bool			ft_parse_texture(char *path, t_img *texture);
int				parse_texture_helper(t_cub3d *cub3d, char *line, int i);
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
void			game_loop(void *param);
void			close_window(void *param);
void			rotate_player(t_cub3d *cub3d, double angle_change);
void			handle_toggles(t_cub3d *cub3d);
void			cast_single_ray(t_cub3d *cub3d, double angle);
void			draw_single_ray(t_cub3d *cub3d, double ray_x, double ray_y);
bool			boundary_and_wall_collision_check(t_cub3d *cub3d, int grid_x,
					int grid_y);
void			update_y_and_x(t_cub3d *cub3d, double px_d, double py_d);
bool			check_wall_rotate(t_cub3d *cub3d, double px_d,
					double py_d, double fps);
bool			check_vertical_wall_hit(t_cub3d *cub3d, t_ray *ray);
void			rotate_player_keys(t_cub3d *cub3d, double fps);
bool			ft_validate_parse_file(t_cub3d *data, int fd);
int				argument_check(int argc, char **argv);
char			**read_map_file(char *map_path, int fd);
bool			ft_is_map_enclosed(char **map);
int				get_max_width(char **map);
char			*pad_line(char *line, int width);
char			**pad_map(char **map);
bool			ft_validate_map(char **map, char *map_path);
bool			is_walkable(char c);
void			print_array(char **array);
void			cast_rays(t_cub3d *cub3d);
double			get_player_angle(char direction);
void			render_frame(t_cub3d *cub3d);
void			init_ray(t_cub3d *cub3d, t_ray *ray, int x);
void			perform_dda(t_cub3d *cub3d, t_ray *ray);
void			calculation_projection(t_cub3d *cub3d, t_ray *ray);
void			draw_column(t_cub3d *cub3d, t_ray *ray, int x);
void			cleanup_cub3d(t_cub3d *cub3d);
void			clean_minimap(t_cub3d *cub3d);
void			clean_texture(t_cub3d *cub3d);
void			clean_img(t_cub3d *cub3d);
void			clean_graphics(t_cub3d *cub3d);

#endif
