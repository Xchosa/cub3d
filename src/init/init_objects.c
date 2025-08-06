
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

	object = get_object();

	object->map = ft_cpy_array_str(cub3d->map);
	if (!object->map)
		return (false);
	object->map_height = get_map_height(cub3d->map);
	object->map_width = get_map_width(cub3d->map);
	object->square_size = return_square_size(cub3d,
			object->map_width, object->map_height);

	return (true);
}
