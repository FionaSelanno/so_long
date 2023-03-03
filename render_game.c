/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:07:10 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 12:39:55 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* convert xpm image to an image suitable for rendering the game.
Store these converted images in game->img[5] */
void	xpm_to_img(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	while (i < 5)
	{
		game->img[i] = mlx_xpm_file_to_image(game->mlx, game->xpm_path[i],
				&width, &height);
		i++;
	}
}

/* store the paths to the xpm images in game->xpm_path[5]. 
This is needed by xpm_to_img()*/
void	set_xpm_path(t_game *game)
{
	game->xpm_path[0] = "./textures/floor.xpm";
	game->xpm_path[1] = "./textures/wall.xpm";
	game->xpm_path[2] = "./textures/player.xpm";
	game->xpm_path[3] = "./textures/collectible.xpm";
	game->xpm_path[4] = "./textures/exit.xpm";
}

/* after converting image, put image to window to render the game. 
Recall this function to rerender the game according to 
the actions taken while playing the game*/
void	put_img(int i, int x_win, int y_win, t_game *game)
{
	x_win *= TILE_SIZE;
	y_win *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->wind, game->img[i], x_win, y_win);
}

/* put image in tile */
void	put_img_to_map(char tile, int x, int y, t_game *game)
{
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

/* read tile per tile to render the game */
void	render_game(t_game *game, t_map *map)
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
