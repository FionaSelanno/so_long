/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:14:28 by fiselann          #+#    #+#             */
/*   Updated: 2023/01/24 12:32:40 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* the keypress event is hooked to this function. Depending on the pressed 
key it recalls put_img_to_map() to rerender the game */
int	hook_keys(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		go_up(game);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		go_down(game);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		go_right(game);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		go_left(game);
	if (keycode == KEY_EXIT)
		exit_game(game);
	return (keycode);
}

/* checks if the next step is valid. If valid then return (1) to 
take the next step */
int	check_next_step(int y, int x, t_game *game)
{
	if (game->map->grid[y][x] == '1')
	{
		ft_putstr_fd("you hit a wall, choose another move\n", 1);
		return (0);
	}
	else if (game->map->grid[y][x] == 'C')
	{
		game->map->collects--;
		game->map->grid[y][x] = 0;
		if (game->map->collects <= 0)
			ft_putstr_fd("all collectibles collected, find the exit\n", 1);
	}
	else if (game->map->grid[y][x] == 'E')
	{
		if (game->map->collects > 0)
		{
			ft_putstr_fd("collect all collectibles first\n", 1);
			return (0);
		}
		else
			exit_game(game);
	}
	return (1);
}

void	go_up(t_game *game)
{
	if (check_next_step(game->y_p - 1, game->x_p, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p, game->y_p - 1, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}

void	go_down(t_game *game)
{
	if (check_next_step(game->y_p + 1, game->x_p, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p, game->y_p + 1, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}

void	go_right(t_game *game)
{
	if (check_next_step(game->y_p, game->x_p + 1, game) == 1)
	{
		put_img_to_map('0', game->x_p, game->y_p, game);
		put_img_to_map('P', game->x_p + 1, game->y_p, game);
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
}
