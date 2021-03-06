/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:57:16 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/16 21:07:56 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images(t_game *game)
{
	game->sprite.down1.img = mlx_xpm_file_to_image(game->mlx, PATH_DOWN,
			&(game->sprite.down1.width), &(game->sprite.down1.height));
	game->sprite.left1.img = mlx_xpm_file_to_image(game->mlx, PATH_LEFT,
			&(game->sprite.left1.width), &(game->sprite.left1.height));
	game->sprite.right1.img = mlx_xpm_file_to_image(game->mlx, PATH_RIGHT,
			&(game->sprite.right1.width), &(game->sprite.right1.height));
	game->sprite.up1.img = mlx_xpm_file_to_image(game->mlx, PATH_UP,
			&(game->sprite.up1.width), &(game->sprite.up1.height));
	game->sprite.tile.img = mlx_xpm_file_to_image(game->mlx, PATH_TILE,
			&(game->sprite.tile.width), &(game->sprite.tile.height));
	game->sprite.wall.img = mlx_xpm_file_to_image(game->mlx, PATH_WALL,
			&(game->sprite.wall.width), &(game->sprite.wall.height));
	game->sprite.item.img = mlx_xpm_file_to_image(game->mlx, PATH_ITEM,
			&(game->sprite.item.width), &(game->sprite.item.height));
	game->sprite.ext.img = mlx_xpm_file_to_image(game->mlx, PATH_EXT,
			&(game->sprite.ext.width), &(game->sprite.ext.height));
	game->sprite.ext2.img = mlx_xpm_file_to_image(game->mlx, PATH_EXT2,
			&(game->sprite.ext2.width), &(game->sprite.ext2.height));
	game->sprite.enemy.img = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY,
			&(game->sprite.enemy.width), &(game->sprite.enemy.height));
	game->sprite.dead.img = mlx_xpm_file_to_image(game->mlx, PATH_DEAD,
			&(game->sprite.dead.width), &(game->sprite.dead.height));
}

void	load_player(t_game *game, int i, int j)
{
	if (game->sprite.down1.health)
	{
		if (!game->lastkey || game->lastkey == 115)
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite.down1.img, j * IMG_SIZE, i * IMG_SIZE);
		if (game->lastkey == 119)
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite.up1.img, j * IMG_SIZE, i * IMG_SIZE);
		if (game->lastkey == 100)
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite.right1.img, j * IMG_SIZE, i * IMG_SIZE);
		if (game->lastkey == 97)
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprite.left1.img, j * IMG_SIZE, i * IMG_SIZE);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite.dead.img, j * IMG_SIZE, i * IMG_SIZE);
	if (!game->count_moves)
	{
		game->sprite.down1.current.x = j;
		game->sprite.down1.current.y = i;
	}
}

void	load_exit(t_game *game, int i, int j)
{
	if (game->verify.collectable <= 0)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.ext2.img,
			j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.ext.img,
			j * IMG_SIZE, i * IMG_SIZE);
}

void	put_tile(t_game *game, int i, int j)
{
	if (game->tile_map[i][j].type == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall.img,
			j * IMG_SIZE, i * IMG_SIZE);
	if (game->tile_map[i][j].type == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.tile.img,
			j * IMG_SIZE, i * IMG_SIZE);
	if (game->tile_map[i][j].type == EXIT)
		load_exit(game, i, j);
	if (game->tile_map[i][j].type == PLAYER)
		load_player(game, i, j);
	if (game->tile_map[i][j].type == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.item.img,
			j * IMG_SIZE, i * IMG_SIZE);
	if (game->tile_map[i][j].type == ENEMY)
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.enemy.img,
			j * IMG_SIZE, i * IMG_SIZE);
}

int	load_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y_axis)
	{
		j = 0;
		while (j < game->x_axis)
		{
			put_tile(game, i, j);
			mlx_string_put(game->mlx, game->win, 5, 15, 0x000000, game->moves);
			j++;
		}
		i++;
	}
	return (0);
}
