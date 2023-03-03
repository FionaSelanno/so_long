/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:44:52 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 10:42:21 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_map *map)
{
	map->exit++;
	if (map->exit > 1)
		ft_exit("Error\nBad map: too many exit points\n", map);
}

void	check_start(t_map *map)
{
	map->start++;
	if (map->start > 1)
		ft_exit("Error\nBad map: too many starting points\n", map);
}

void	go_left(t_game *game)
{
	if (check_next_step(game->y_p, game->x_p - 1, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p - 1, game->y_p, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}
