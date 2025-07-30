
#include "cub3d.h"
#include "parse.h"


char	**read_map_file(char *map_path)
{
	int		fd;
	char	*line;
	char	*content;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0);
		return (NULL);
	content = ft_strdup("");
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, &line);
		if (!line)
			break ;
		tmp = content;
		content = ft_strjon(content, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (content); 
}
