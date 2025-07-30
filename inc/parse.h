
#ifndef PARSE_H
# define PARSE_H

int		ft_validate_parse_file(t_cub3d *data, int fd);
int		argument_check(int argc, char **argv);


char	**read_map_file(char *map_path);

#endif
