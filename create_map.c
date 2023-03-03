/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:59:10 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 12:04:19 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* initialize t_map */
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

/* check validation map->grid */
void	check_grid(t_map *map)
{
	int	i;
	int	height;

	i = 0;
	height = map->height;
	check_rectangle(map->grid, map);
	while (height > 0)
	{
		check_wall(i, map->grid[i], map);
		i++;
		height--;
	}
	check_comps(map);
	check_path(map);
}

/* read .ber line per line and store the lines in map->grid */
void	set_grid(t_map *map)
{
	char	*line;
	char	*total;

	line = get_next_line(map->fd);
	if (ft_strncmp(line, "ERROR", 5) == 0 || !line)
		ft_exit("Error\nreading file\n", map);
	total = NULL;
	while (line)
	{
		map->height++;
		total = ft_strjoin(total, line);
		free(line);
		if (!total)
		{
			free(line);
			ft_exit("Error\nin strjoin\n", map);
		}
		line = get_next_line(map->fd);
		if (ft_strncmp(line, "ERROR", 5) == 0)
			ft_exit("Error\nreading file\n", map);
	}
	free(line);
	map->grid = ft_split(total, '\n');
	free(total);
}

/* duplicate grid to use it in check_path() */
char	**dup_grid(t_map *map)
{
	int		len;
	int		i;
	char	**dup;

	len = map->height;
	dup = malloc(sizeof(char *) * (len + 1));
	if (!dup)
		ft_exit("Error\nMemory allocation", map);
	i = 0;
	while (i < len)
	{
		dup[i] = ft_strdup(map->grid[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

/* starting point for creating map*/
void	create_map(char *map_path, t_map *map)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	check_fd(fd, map);
	map_init(map, fd);
	set_grid(map);
	check_grid(map);
	close(fd);
}
