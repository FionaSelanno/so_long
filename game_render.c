/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:07:10 by fiselann          #+#    #+#             */
/*   Updated: 2022/12/13 12:12:39 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	put_img(int i, int x_win, int y_win, t_game *game)
{
	x_win *= TILE_SIZE;
	y_win *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->wind, game->img[i], x_win, y_win); //push image to window
}

void	put_img_to_map(char tile, int x, int y, t_game *game)
{
	//printf("tile: %c\n", tile);
	if (tile == 'P')
	{
		game->x_p = x;
		game->y_p = y;
		put_img(0, x, y, game);
		put_img(2, x, y, game);
	}
	else if (tile == 'C')
	{
		put_img(0, x, y, game);
		put_img(3, x, y, game);
	}
	else if (tile == 'E')
		put_img(4, x, y, game);
	else if (tile == '1')
		put_img(1, x, y, game);
	else if (tile == '0')
		put_img(0, x, y, game);
}

void	render_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	game->map = map;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			put_img_to_map(game->map->grid[y][x], x, y, game);
			x++;
		}
		y++;
	}
}