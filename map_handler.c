#include "so_long.h"
#include <stdio.h>
#include <string.h>


void	map_init(t_map *map, int fd)
{
	map->fd = fd;
	map->grid = NULL;
	map->exit = 0;
	map->collects = 0;
	map->start = 0;
	map->width = 0;
	map->height = 0;
	map->e_check = 0;
	map->c_check = 0;
}

void	check_grid(t_map *map)
{
	int	i;

	i = -1;
	check_rectangle(map->grid, map);
	while (map->grid[++i])
		check_wall(i, map->grid[i], map);
	check_comps(map);
	check_path(map);
}

void set_grid(t_map *map)
{
	char *line;
	char *total;

	line = get_next_line(map->fd);
	if (ft_strncmp(line, "ERROR", 5) == 0 || !line)
		ft_exit("bad parsing 1: gnl\n", map);
	total = NULL;
	while (line)
	{
		map->height++;
		total = ft_strjoin(total, line); //total is already being freed in ft_strjoin
		free(line);
		if (!total)
		{
			free(line);
			ft_exit("error read: strjoin\n", map);
		}
		line = get_next_line(map->fd);
		if (ft_strncmp(line, "ERROR", 5) == 0)
			ft_exit("error read: gnl\n", map);
	}
	free(line);
	map->grid = ft_split(total, '\n');
	free(total);
	//printf("map->height: %d\n", map->height);
	//check_alloc(map->grid, "error split\n", map);
}

char	**dup_grid(t_map *map)
{
	int	i;
	char **dup;

	i = 0;
	while(map->grid[i])
		i++;
	dup = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while(map->grid[i])
	{
		dup[i] = ft_strdup(map->grid[i]);
		i++;
	}
	return (dup);
}

void	handle_map(char *map_path, t_map *map)
{
	int fd;

	fd = open(map_path, O_RDONLY);
	check_fd(fd, map);
	map_init(map, fd);
	set_grid(map);
	check_grid(map);
	close(fd);
}
