/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:32:25 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 12:41:31 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if grid is rectangle */
void	check_rectangle(char **grid, t_map *map)
{
	int	x;
	int	y;
	int	width;

	y = 0;
	width = 0;
	while (y < map->height)
	{
		x = 0;
		while (grid[y][x] != '\0')
			x++;
		if (width != 0 && x != width)
			ft_exit("Error\nBad map: not rectangle\n", map);
		else
			width = x;
		y++;
	}
	map->width = width;
}

/* check if the walls of the grid are correct */
void	check_wall(int i, char *row, t_map *map)
{
	int	j;

	if (i == 0 || i == (map->height - 1))
	{
		j = 0;
		while (row[j])
		{
			if (row[j] != '1')
				ft_exit("Error\nBad map: top/bottom wall\n", map);
			j++;
		}	
	}
	else
	{
		if (row[0] != '1' || row[map->width - 1] != '1')
			ft_exit("Error\nBad map: side wall\n", map);
	}
}

/* check if there is an exit and starting point, count all the collectibles. 
check if all tiles of grid are valid (only "01CEP" char's) */
void	check_comps(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x] != '\0')
		{
			if (ft_strchr("01CEP", map->grid[y][x]) == NULL)
				ft_exit("Error\nBad map: char\n", map);
			if (map->grid[y][x] == 'E')
				check_exit(map);
			else if (map->grid[y][x] == 'C')
				map->collects++;
			else if (map->grid[y][x] == 'P')
				check_start(map);
			x++;
		}
		y++;
	}
	if (map->exit < 1 || map->start < 1 || map->collects < 1)
		ft_exit("Error\nBad map\n", map);
}

/* walk trough grid to see if the exit and all collectibles are accesible */
void	walk_through_grid(char **grid, int x, int y, t_map *map)
{
	int	w;
	int	h;

	if (grid[y][x] == 'C')
		map->c_check++;
	if (grid[y][x] == 'E')
		map->e_check = 1;
	w = map->width;
	h = map->height;
	if (x < 0 || x >= w || y < 0 || y >= h || grid[y][x] == '1'
			|| grid[y][x] == 'X' || grid[y][x] == 'E')
		return ;
	grid[y][x] = 'X';
	walk_through_grid(grid, x, y + 1, map);
	walk_through_grid(grid, x, y - 1, map);
	walk_through_grid(grid, x + 1, y, map);
	walk_through_grid(grid, x - 1, y, map);
	return ;
}

/* check if the path to exit and collectibels is valid */
void	check_path(t_map *map)
{
	int		x;
	int		y;
	char	**copy;

	y = 0;
	x = 0;
	copy = dup_grid(map);
	while (copy[y] && copy[y][x] != 'P')
	{
		x = 0;
		y++;
		while (copy[y][x] && copy[y][x] != 'P')
			x++;
	}
	walk_through_grid(copy, x, y, map);
	ft_freetab(copy, map->height);
	if (map->collects != map->c_check || map->exit != map->e_check)
		ft_exit("Error\nBad map: no valid path\n", map);
}
