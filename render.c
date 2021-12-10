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

static void get_images(t_game *game)
{
	game->sprite.down1.img = mlx_xpm_file_to_image(game->mlx, "./sprites/down1.xpm", &(game->sprite.down1.width), &(game->sprite.down1.height));
	game->sprite.tile.img = mlx_xpm_file_to_image(game->mlx, "./sprites/tile.xpm", &(game->sprite.tile.width), &(game->sprite.tile.height));
	game->sprite.wall.img = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &(game->sprite.wall.width), &(game->sprite.wall.height));
	game->sprite.item.img = mlx_xpm_file_to_image(game->mlx, "./sprites/item.xpm", &(game->sprite.item.width), &(game->sprite.item.height));
	game->sprite.exit.img = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &(game->sprite.exit.width), &(game->sprite.exit.height));
}

int	load_game(t_game *game)
{
	int	i;
	int	j;
	static int	flag = 0;

	get_images(game);
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
				mlx_put_image_to_window(game->mlx, game->win, game->sprite.exit.img, j * IMG_SIZE, i * IMG_SIZE);
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
	if (!flag)
	{
		printf(">: down x %c\n", game->sprite.down1.t_down);
		printf(">: up x %c\n", game->sprite.down1.t_up);
		printf(">: right x %c\n", game->sprite.down1.t_right);
		printf(">: left x %c\n", game->sprite.down1.t_left);
		flag += 1;
	}
	return (0);
}

// void	load_sprites(t_game *game,int *start)
// {
// 	int x;
// 	int	y;
		
// 	if (*start == 0)
// 	{
// 		game->sprite.down1.img = mlx_xpm_file_to_image(game->mlx, "./sprites/down1.xpm", &(game->sprite.down1.width), &(game->sprite.down1.height));
// 		game->sprite.up1.img = mlx_xpm_file_to_image(game->mlx, "./sprites/up1.xpm", &(game->sprite.up1.width), &(game->sprite.up1.height));
// 		game->sprite.right1.img = mlx_xpm_file_to_image(game->mlx, "./sprites/right1.xpm", &(game->sprite.right1.width), &(game->sprite.right1.height));
// 		game->sprite.left1.img = mlx_xpm_file_to_image(game->mlx, "./sprites/left1.xpm", &(game->sprite.left1.width), &(game->sprite.left1.height));
// 		game->sprite.tile.img = mlx_xpm_file_to_image(game->mlx, "./sprites/tile.xpm", &(game->sprite.tile.width), &(game->sprite.tile.height));
// 		game->sprite.wall.img = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &(game->sprite.wall.width), &(game->sprite.wall.height));
// 		game->sprite.player_bf.x = 0;
// 		game->sprite.player_bf.y = 0;
// 		game->sprite.player_af.x = 0;
// 		game->sprite.player_af.y = 0;
// 		y = 0;
// 		while (y < 16)
// 		{	
// 			x = 0;
// 			while (x < 32)
// 			{
// 				if (y == 0 || y == 15 || ((y < 15 || y > 0) && (x == 0 || x == 31)))
// 					mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall.img, x * 20, y * 30);
// 				else
// 					mlx_put_image_to_window(game->mlx, game->win, game->sprite.tile.img, x * 20, y * 30);
// 				x++;
// 			}
// 			y++;
// 		}
// 		mlx_put_image_to_window(game->mlx, game->win, game->sprite.down1.img, game->sprite.player_bf.x, game->sprite.player_bf.y);	
// 		*start = 1;
// 	}
// }

// int	load_game(t_game *game)
// {
// 	if (game->sprite.player_af.y < game->sprite.player_bf.y)
// 	{	
// 		load_static_tiles(game);
// 		mlx_put_image_to_window(game->mlx, game->win, game->sprite.up1.img, game->sprite.player_af.x, game->sprite.player_af.y);
// 		game->sprite.player_bf.y = game->sprite.player_af.y;
// 	}
// 	else if (game->sprite.player_af.y > game->sprite.player_bf.y)
// 	{
// 		load_static_tiles(game);
// 		mlx_put_image_to_window(game->mlx, game->win, game->sprite.down1.img, game->sprite.player_af.x, game->sprite.player_af.y);
// 		game->sprite.player_bf.y = game->sprite.player_af.y;
// 	}
// 	else if (game->sprite.player_af.x > game->sprite.player_bf.x)
// 	{
// 		load_static_tiles(game);
// 		mlx_put_image_to_window(game->mlx, game->win, game->sprite.right1.img, game->sprite.player_af.x, game->sprite.player_af.y);
// 		game->sprite.player_bf.x = game->sprite.player_af.x;
// 	}
// 	else if (game->sprite.player_af.x < game->sprite.player_bf.x)
// 	{
// 		load_static_tiles(game);
// 		mlx_put_image_to_window(game->mlx, game->win, game->sprite.left1.img, game->sprite.player_af.x, game->sprite.player_af.y);
// 		game->sprite.player_bf.x = game->sprite.player_af.x;
// 	}
// 	return (0);
// }

// //Adicionar condição para que não aconteça nada caso eu aperte outra tecla que não esteja mapeado. Posso procurar uma função para isso ou criar uma condição para renderizar a última sprite
// void	load_static_tiles(t_game *game)
// {
// 	int x;
// 	int	y;	

// 	y = 0;
// 	while (y < 16)
// 	{	
// 		x = 0;
// 		while (x < 32)
// 		{
// 			if (y == 0 || y == 15 || ((y < 15 || y > 0) && (x == 0 || x ==31)))
// 				mlx_put_image_to_window(game->mlx, game->win, game->sprite.wall.img, x * 20, y * 30);
// 			else
// 				mlx_put_image_to_window(game->mlx, game->win, game->sprite.tile.img, x * 20, y * 30);
// 			x++;
// 		}
// 		y++;
// 	}
// }
