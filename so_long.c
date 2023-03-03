/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:15:52 by fiselann          #+#    #+#             */
/*   Updated: 2022/12/13 13:39:47 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

/* STEPS:
1. parse map
2. initialise structure, mlx_init()
3. render, mlx_put_image_to_window())
4. interaction with user input, with mlx_key_hook() you can react on events.
5. When exiting the game:
	- mlx_destroy_window()
	- mlx_destry_display() + free()
	- sprites: mlx_destroy_image();
*/

void initialize_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->wind = mlx_new_window(game->mlx, TILE_SIZE * map->width, TILE_SIZE * map->height, "so_long");
	game->map = map;
	game->moves = 0;
	set_xpm_path(game);
	xpm_to_img(game);
	
}

void	xpm_to_img(t_game *game)
{
	int	i;
	int	width;
	int	height;
	
	i = 0;
	while(i < 5)
	{
		game->img[i] = mlx_xpm_file_to_image(game->mlx, game->xpm_path[i], &width, &height);
		i++;
	}
}

void set_xpm_path(t_game *game)
{
	game->xpm_path[0] = "./img/floor.xpm";
	game->xpm_path[1] = "./img/wall.xpm";
	game->xpm_path[2] = "./img/player.xpm";
	game->xpm_path[3] = "./img/collectible.xpm";
	game->xpm_path[4] = "./img/exit.xpm";
}

int exit_game(t_game *game)
{
	ft_freetab(game->map->grid, game->map->height);
	mlx_destroy_window(game->mlx, game->wind);
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
	

	if (argc != 2)
		return (EXIT_FAILURE);
	handle_map(argv[1], &map);
	
	//initialise structure
	initialize_game(&game, &map);

	//render game
	render_map(&game, &map);
	
	//hook on events
	//all hooks are nothing more than a function that gets called whenever an event is triggerd: void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
	//This hooks on to the keypress event.
	//the keyPress event(2) is registered with the according KeyPressMask (1L<0), meaning the window only has to listen to the keyPress event and can ignore other events.
	mlx_hook(game.wind, 2, 1L<0, &hook_keys, &game);
	//mlx_key_hook(game.wind, hook_keys, &game);

	//the destroyNotify event (17) is registered nog KeyMask event, cause I also have to listen to the click event, 
	mlx_hook(game.wind, 17, 0L, &exit_game, &game);

	//hook on key event: mlx_loop_hook(void *mlx, int render_next_frame(void *YourStruct), yourstruct *YourStruct )
	//mlx_loop_hook(game.mlx, re_render, &game);
	//exit game
	
	mlx_loop(game.mlx);


	return (EXIT_SUCCESS);
}

