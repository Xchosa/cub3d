
#include "cub3d.h"
#include "init.h"

t_object	*get_object(void)
{
	static t_object	object;

	return (&object);
}

bool	init_object(t_cub3d *cub3d)
{
	t_object	*object;

	bash = get_bash();

	object->map = cpychar_arr(cub3d->map);
	if (!object->map)
		return (false);
	object->map_height = get_map_height(cub3d->map);
	object->map_width = get_map_width(cub3d->map);
	bash->square_size = return_square_size(cub3d,
			s_object->map_widht, object->map_height);

	return (true);
}
