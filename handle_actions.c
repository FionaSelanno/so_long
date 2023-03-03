/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:14:28 by fiselann          #+#    #+#             */
/*   Updated: 2022/12/13 13:46:14 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		hook_keys(int keycode, t_game *game)
{
	
	(void)game;
	if (keycode == KEY_UP || keycode == KEY_W)
		go_up(game);
	if	(keycode == KEY_DOWN || keycode == KEY_S)
		go_down(game);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		go_right(game);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		go_left(game);
	if (keycode == KEY_EXIT)
		exit_game(game);
	return (keycode);
}

int check_next_step(int y, int x, t_game *game)
{

	if(game->map->grid[y][x] == '1')
	{
		ft_putstr_fd("you hit a wall, choose another move\n", 1);
		return (0);
	}
	else if(game->map->grid[y][x] == 'C')
	{
		game->map->collects--;
		if (game->map->collects <= 0)
			ft_putstr_fd("all collectibles collected, find the exit\n", 1);
	}
	else if(game->map->grid[y][x] == 'E')
	{
		if (game->map->collects > 0)
		{
			ft_putstr_fd("collect all collectibles first, before exiting the game\n", 1);
			return (0);
		}
		else
			exit_game(game);
	}
		return (1);
}

void	go_up(t_game *game)
{
	if(check_next_step(game->y_p - 1, game->x_p, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p, game->y_p - 1, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}

void	go_down(t_game *game)
{
	if(check_next_step(game->y_p + 1, game->x_p, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p, game->y_p + 1, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}

void	go_right(t_game *game)
{
	if(check_next_step(game->y_p, game->x_p + 1, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p + 1, game->y_p, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}

void	go_left(t_game *game)
{
	if(check_next_step(game->y_p, game->x_p - 1, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p - 1, game->y_p, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}

void	set_position(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	printf("old position y: %d, x: %d\n", y, x);
	while (game->map->grid[y] && game->map->grid[y][x] != 'P')
    {
        x  = 0;
        y++;
        while (game->map->grid[y][x] && game->map->grid[y][x] != 'P')
            x++;
    }
	game->x_p = x;
	game->y_p = y;
	printf("new position y: %d, x: %d\n", y, x);
}