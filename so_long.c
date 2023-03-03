/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:15:52 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 12:40:09 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->wind = mlx_new_window(game->mlx, TILE_SIZE * map->width,
			TILE_SIZE * map->height, "so_long");
	game->map = map;
	game->moves = 0;
	set_xpm_path(game);
	xpm_to_img(game);
}

/* before exiting the game, free grid, destroy every image, 
destroy window and free memory off the game */
int	exit_game(t_game *game)
{
	int	i;

	ft_printf("Congratz, You have completed the game!\n");
	if (game->map->grid)
		ft_freetab(game->map->grid, game->map->height);
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(game->mlx, game->img[i]);
		i++;
	}
	mlx_destroy_window(game->mlx, game->wind);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nNo valid argument");
		return (EXIT_FAILURE);
	}
	if (ft_strrcmp(argv[1], ".ber", 4) == 0)
	{
		ft_printf("Error\nWrong input\n");
		return (EXIT_FAILURE);
	}	
	create_map(argv[1], &map);
	initialize_game(&game, &map);
	render_game(&game, &map);
	mlx_hook(game.wind, 2, 1L < 0, &hook_keys, &game);
	mlx_hook(game.wind, 17, 0L, &exit_game, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
