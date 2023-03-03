/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:24 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 10:57:38 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_fd(int fd, t_map *map)
{
	if (fd < 0)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
}

void	check_alloc(char **str, char *info, t_map *map)
{
	if (!str)
	{
		free_map(map);
		ft_exit(info, map);
	}
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

/* compare 2 strings starting from the end off the strings */
int	ft_strrcmp(char *str1, char *str2, int len)
{
	int	x;

	x = ft_strlen(str1);
	if (x < len)
		return (0);
	while (len > 0)
	{
		if (str1[x - 1] != str2[len - 1])
			return (0);
		x--;
		len--;
	}
	return (1);
}
