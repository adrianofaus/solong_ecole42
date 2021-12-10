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

	if (keycode == 119 && game->sprite.down1.t_up != WALL)
	{
			temp = game->sprite.down1.current;
			game->tile_map[temp.y][temp.x].type = EMPTY;
			game->tile_map[temp.y - 1][temp.x].type = PLAYER;
	}
	if (keycode == 115 && game->sprite.down1.t_down != WALL)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + 1][temp.x].type = PLAYER;
	}
	if (keycode == 100 && game->sprite.down1.t_right != WALL)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x + 1].type = PLAYER;
	}
	if (keycode == 97 && game->sprite.down1.t_left != WALL)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x - 1].type = PLAYER;
	}
	if (keycode == 65307)
	{
		free_all(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);		
		exit(0);
	}
	return(0);
}
