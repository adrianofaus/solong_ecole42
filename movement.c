/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:59:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/16 01:24:46 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_moves(t_game *game)
{
	if (game->count_moves)
		free_null(game->moves);
	++game->count_moves;
	game->moves = ft_itoa(game->count_moves);
}

void	move_to_empty(t_game *game, int y_offset, int x_offset)
{
	int	y_now;
	int	x_now;

	y_now = game->sprite.down1.current.y;
	x_now = game->sprite.down1.current.x;
	game->tile_map[y_now][x_now].type = EMPTY;
	game->tile_map[y_now + y_offset][x_now + x_offset].type = PLAYER;
	game->sprite.down1.current.y += y_offset;
	game->sprite.down1.current.x += x_offset;
}

void	move_to_exit(t_game *game, int y_offset, int x_offset)
{
	int	y_now;
	int	x_now;

	y_now = game->sprite.down1.current.y;
	x_now = game->sprite.down1.current.x;
	game->tile_map[y_now][x_now].type = EMPTY;
	game->tile_map[y_now + y_offset][x_now + x_offset].type = EXIT;
	game->sprite.down1.current.y += y_offset;
	game->sprite.down1.current.x += x_offset;
	game->run = 0;
}

int	move_to(t_game *game, int y_offset, int x_offset)
{
	int		y_now;
	int		x_now;
	char	dir;

	y_now = game->sprite.down1.current.y;
	x_now = game->sprite.down1.current.x;
	dir = game->tile_map[y_now + y_offset][x_now + x_offset].type;
	if (dir != WALL && dir != EXIT && dir != ENEMY)
	{
		if (dir == ITEM)
			game->verify.collectable--;
		move_to_empty(game, y_offset, x_offset);
		return (1);
	}
	else if (dir == EXIT && game->verify.collectable <= 0)
	{
		move_to_exit(game, y_offset, x_offset);
		return (1);
	}
	else if (dir == ENEMY)
	{	
		printf("%d\n",game->sprite.down1.health);
		game->sprite.down1.health = 0;
		printf("%d\n",game->sprite.down1.health);
		game->run = 0;
		return (0);
	}
	return (0);
}

int	input(int key, t_game *game)
{
	int	y_offset;
	int	x_offset;

	game->lastkey = key;
	y_offset = 0;
	x_offset = 0;
	if (key == 65307)
		end_game(game);
	if (game->run)
	{
		if (key == 119)
			y_offset = -1;
		else if (key == 115)
			y_offset = 1;
		else if (key == 100)
			x_offset = 1;
		else if (key == 97)
			x_offset = -1;
	}
	if (game->run)
		if (move_to(game, y_offset, x_offset))
			game->frame = 1;
	return (0);
}
