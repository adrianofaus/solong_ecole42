/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:57:16 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 11:19:52 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_images(t_game *game)
{
	game->sprite.down1.img = mlx_xpm_file_to_image(game->mlx, "./sprites/down1.xpm", &(game->sprite.down1.width), &(game->sprite.down1.height));
	game->sprite.tile.img = mlx_xpm_file_to_image(game->mlx, "./sprites/tile.xpm", &(game->sprite.tile.width), &(game->sprite.tile.height));
	game->sprite.wall.img = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &(game->sprite.wall.width), &(game->sprite.wall.height));
	game->sprite.item.img = mlx_xpm_file_to_image(game->mlx, "./sprites/item.xpm", &(game->sprite.item.width), &(game->sprite.item.height));
	game->sprite.exit.img = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &(game->sprite.exit.width), &(game->sprite.exit.height));
	game->sprite.exit2.img = mlx_xpm_file_to_image(game->mlx, "./sprites/exit2.xpm", &(game->sprite.exit2.width), &(game->sprite.exit2.height));
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
			if (game->tile_map[i][j].type == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall.img, j * IMG_SIZE, i * IMG_SIZE);
			if (game->tile_map[i][j].type == EMPTY)
				mlx_put_image_to_window(game->mlx, game->win, game->sprite.tile.img, j * IMG_SIZE, i * IMG_SIZE);
			if (game->tile_map[i][j].type == EXIT)
			{
				if (game->verify.collectable == game->verify.item)
					mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit2.img, j * IMG_SIZE, i * IMG_SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit.img, j * IMG_SIZE, i * IMG_SIZE);
			}
			if (game->tile_map[i][j].type == PLAYER)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->sprite.down1.img, j * IMG_SIZE, i * IMG_SIZE);
				game->sprite.down1.current.x = j;
				game->sprite.down1.current.y = i;
				game->sprite.down1.t_down = game->tile_map[i + 1][j].type;
				game->sprite.down1.t_up = game->tile_map[i - 1][j].type;
				game->sprite.down1.t_right = game->tile_map[i][j + 1].type;
				game->sprite.down1.t_left = game->tile_map[i][j - 1].type;
			}
			if (game->tile_map[i][j].type == ITEM)
				mlx_put_image_to_window(game->mlx, game->win, game->sprite.item.img, j * IMG_SIZE, i * IMG_SIZE);				
			j++;
		}
		i++;
	}
	return (0);
}
