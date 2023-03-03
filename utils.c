#include "so_long.h"

void	check_fd(int fd, t_map *map)
{
	(void)map;
	if (fd < 0)
	//free_map(map);
	exit(0);
}

void	check_alloc(char **str, char *info, t_map *map)
{
	if (!str)
	free_map(map);
	ft_exit(info, map);
}

void	ft_exit(char *message, t_map *map)
{
	ft_putstr_fd(message, 1);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	if (map->grid)
		ft_freetab(map->grid, map->height);
	if (map->fd)
		close(map->fd);
}

/****TODO: delete these functions*****/
void	print_mapstruct(t_map *map)
{
	printf("print map struct: ");
	printf("fd: %d\n", map->fd);
	print_tab(map->grid);
	printf("exit: %d\n", map->exit);
	printf("collects: %d\n", map->collects);
	printf("start: %d\n", map->start);
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
}

void	print_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
}