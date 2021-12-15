/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:53:18 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/15 01:36:32 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PATH_DOWN "./sprites/down1.xpm"
# define PATH_LEFT "./sprites/left1.xpm"
# define PATH_RIGHT "./sprites/right1.xpm"
# define PATH_UP "./sprites/up1.xpm"
# define PATH_TILE "./sprites/tile.xpm"
# define PATH_WALL "./sprites/wall.xpm"
# define PATH_ITEM "./sprites/item.xpm"
# define PATH_EXT "./sprites/exit.xpm"
# define PATH_EXT2 "./sprites/exit2.xpm"

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "../libft/libft.h"

/* SPRITE SIZE */
#define IMG_SIZE 32

/* TILES */

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	ITEM = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'A',
	FOLLOWER = 'F'
}	t_tiletype;

/* STRUCTURES */

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef	struct s_tile
{
	char type;
}	t_tile;

typedef	struct s_image
{
	void	*img;
	int		width;
	int		height;
}			t_image;

typedef struct s_player
{
	void		*img;
	int			width;
	int			height;
	t_vector	current;
	char		t_up;
	char		t_down;
	char		t_left;
	char		t_right;
}			t_player;

typedef struct s_sprite
{
	t_player	down1;
	t_image		up1;
	t_image		left1;
	t_image		right1;
	t_image		wall;
	t_image		tile;
	t_image		ext;
	t_image		ext2;
	t_image		item;
	t_image		collectable;
	t_vector	player_bf;
	t_vector	player_af;
}			t_sprite;

typedef struct s_validator
{
	int	px;
	int	py;
	int	exit;
	int	collectable;
	int item;
	int player;
}	t_validate;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		lastkey;
	int			moves;
	t_sprite	sprite;
	int			x_axis;
	int			y_axis;
	int			items;
	int			run;
	t_tile		**tile_map;
	t_validate	verify;
}	t_game;

/* FUNCTIONS */

int		validate_file(int argc, char **file);
int		game_init(char *map, t_game *game);
int		input(int keycode, t_game *game);
int		load_game(t_game *game);
int		map_gen(char *map, t_game *game);
char	validate_tile(char *tile, t_game *game);
int		error(char	*msg);
void	free_all(t_game *game);
void	print_map(t_game *game);
void	free_images(t_game *game);
void	get_images(t_game *game);
int		end_game(t_game *game);

#endif
