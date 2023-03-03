#include "so_long.h"

void	check_rectangle(char **grid, t_map *map)
{
	int x;
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
			ft_exit("bad map: not rectangle\n", map);
		else
			width = x;
		y++;
	}
	map->width = width;
}

void	check_wall(int i, char *row, t_map *map)
{
	int j;

	if (i == 0 || i == map->height - 1) //check if top wall is valid
	{
		j = 0;
		while (row[j])
		{
			if (row[j] != '1')
				ft_exit("bad map: top wall\n", map);
			j++;
		}	
	}
	else
	{
		if (row[0] != '1' && row[map->width - 1] != '1')
			ft_exit("bad map: side wall\n", map);
	}
}

void	check_comps(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	printf("begin map->height: %d\n", map->height);
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x] != '\0')
		{
			if (ft_strchr("01CEP", map->grid[y][x]) == NULL)
				ft_exit("bad map: char\n", map);
			if (map->grid[y][x] == 'E')
			{
				map->exit++;
				if (map->exit > 1)
					ft_exit("bad map: too many exit points\n", map);
			}
			else if (map->grid[y][x] == 'C')
				map->collects++;
			else if (map->grid[y][x] == 'P')
			{
				map->start++;
				if (map->start > 1)
					ft_exit("bad map: too many starting points\n", map);
			}
			x++;
		}
		y++;
	}
}

void	walk_through_grid(char **grid, int x, int y, t_map *map)
{
	int	w;
	int	h;

	if (grid[y][x] == 'C')
		map->c_check ++;
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

void check_path(t_map *map)
{
    int x;
    int y;
	char **copy;
    //get starting position
	y = 0;
	copy = dup_grid(map);
    while (copy[y] && copy[y][x] != 'P')
    {
        x  = 0;
        y++;
        while (copy[y][x] && copy[y][x] != 'P')
            x++;
    }
    walk_through_grid(copy, x, y, map);
    if (map->collects != map->c_check || map->exit != map->e_check)
        ft_exit("no valid path\n", map);
}
