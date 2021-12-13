/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:59:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 11:20:39 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_to(int keycode, t_game *game)
{
	t_vector	temp;

	printf("collectable %d\nitems %d\nt_up %c\nt_down %c\nt_right %c\nt_left %c\n----------\n", game->verify.collectable, game->verify.item,game->sprite.down1.t_up, game->sprite.down1.t_down, game->sprite.down1.t_right, game->sprite.down1.t_left);
	if (keycode == 119)
	{
		if (game->sprite.down1.t_up == ITEM)
			game->verify.item++;
		if (game->sprite.down1.t_up != WALL && game->sprite.down1.t_up != EXIT)
		{
			temp = game->sprite.down1.current;
			game->tile_map[temp.y][temp.x].type = EMPTY;
			game->tile_map[temp.y - 1][temp.x].type = PLAYER;
		}
	}
	if (keycode == 115)
	{
		if (game->sprite.down1.t_down == ITEM)
			game->verify.item++;
		if (game->sprite.down1.t_down != WALL && game->sprite.down1.t_down != EXIT)
		{
			temp = game->sprite.down1.current;
			game->tile_map[temp.y][temp.x].type = EMPTY;
			game->tile_map[temp.y + 1][temp.x].type = PLAYER;
		}
	}
	if (keycode == 100)
	{
		if (game->sprite.down1.t_right == ITEM)
			game->verify.item++;
		if (game->sprite.down1.t_right != WALL && game->sprite.down1.t_right != EXIT)
		{
			temp = game->sprite.down1.current;
			game->tile_map[temp.y][temp.x].type = EMPTY;
			game->tile_map[temp.y][temp.x + 1].type = PLAYER;
		}
	}
	if (keycode == 97)
	{
		if(game->sprite.down1.t_left == ITEM)
			game->verify.item++;
		if (game->sprite.down1.t_left != WALL && game->sprite.down1.t_left != EXIT)
		{
			temp = game->sprite.down1.current;
			game->tile_map[temp.y][temp.x].type = EMPTY;
			game->tile_map[temp.y][temp.x - 1].type = PLAYER;
		}
		else if (game->sprite.down1.t_left == EXIT && game->verify.collectable == game->verify.item)
		{
			temp = game->sprite.down1.current;
			game->tile_map[temp.y][temp.x].type = EMPTY;
			game->tile_map[temp.y][temp.x - 1].type = PLAYER;
		}
	}
	if (keycode == 65307)
	{
		free_images(game);
		free_all(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);		
		exit(0);
	}
	return(0);
}
