/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:59:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/15 01:34:02 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_to(t_game *game, char dir, int sum_y, int sum_x)
{
	t_vector	temp;
	if (dir != WALL && dir != EXIT)
	{
		if (dir == ITEM)
			game->verify.item++;
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + sum_y][temp.x + sum_x].type = PLAYER;
		return (1);
	}
	else if (dir == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + sum_y][temp.x + sum_x].type = EXIT;
		game->run = 0;
		return (1);
	}
	return (0);
}

int	input(int key, t_game *game)
{
	if (game->run)
	{
		if (key == 119)
		{
			game->lastkey = 'W';
			if (move_to(game, game->sprite.down1.t_up, -1, 0))
				printf("Moves: %d\n", ++game->moves);
		}
		if (key == 115)
		{
			game->lastkey = 'S';
			if (move_to(game, game->sprite.down1.t_down, 1, 0))
				printf("Moves: %d\n", ++game->moves);
		}
		if (key == 100)
		{
			game->lastkey = 'D';
			if (move_to(game, game->sprite.down1.t_right, 0, 1))
				printf("Moves: %d\n", ++game->moves);
		}
		if (key == 97)
		{
			game->lastkey = 'A';
			if (move_to(game, game->sprite.down1.t_left, 0, -1))
				printf("Moves: %d\n", ++game->moves);
		}
	}
	if (key == 65307)
		end_game(game);
	return(0);
}
