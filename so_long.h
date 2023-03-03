#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "./libft/libft.h"
# include <stdio.h>

# define TILE_SIZE 32

/* map data */
typedef struct s_map {
	int		fd;
	char 	**grid;
	int		exit;
	int		collects;	
	int		start;
	int		e_check;
	int		c_check;
	int		width;
	int		height;
} t_map;

/* game data*/
typedef struct s_game {
	void	*mlx;
	void	*wind;
	void	*img[5];
	void	*xpm_path[5];
	int		x_p;
	int		y_p;
	int		moves;
	t_map	*map;
}	t_game;

enum	keycodes{
	KEY_UP = 126,
	KEY_W = 13,
	KEY_DOWN = 125,
	KEY_S = 1,
	KEY_A = 0,
	KEY_LEFT = 123,
	KEY_D = 2,
	KEY_RIGHT = 124,
	KEY_EXIT = 53
};

/* TODO: delete these functions*/
void	print_mapstruct(t_map *map);
void	print_tab(char **str);

/* map handlers */
void	map_init(t_map *map, int fd);
void	set_grid(t_map *map);
void	check_grid(t_map *map);
void	handle_map(char *map_path, t_map *map);
char	**dup_grid(t_map *map);
void	check_rectangle(char **grid, t_map *map);
void	check_wall(int i, char *row, t_map *map);
void	check_comps(t_map *map);
void	walk_trough_grid(char **grid, int x, int y, t_map *map);
void 	check_path(t_map *map);

/* render game */
void 	initialize_game(t_game *game, t_map *map);
void	xpm_to_img(t_game *game);
void 	set_xpm_path(t_game *game);
void	put_img(int i, int x_win, int y_win, t_game *game);
void	put_img_to_map(char tile, int x_win, int y_win, t_game *game);
void	render_map(t_game *game, t_map *map);

/* handle actions*/
int		hook_keys(int keycode, t_game *game);
void	go_up(t_game *game);
void	go_down(t_game *game);
void	go_right(t_game *game);
void	go_left(t_game *game);
int 	check_next_step(int y, int x, t_game *game);
int 	exit_game(t_game *game);

/* functions */
void	check_fd(int fd, t_map *map);
void	check_alloc(char **str, char *info, t_map *map);
void	ft_exit(char *message, t_map *map);
void	free_map(t_map *map);
void	set_position(t_game *game);

#endif