/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:59:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/14 21:47:23 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_up != WALL && game->sprite.down1.t_up != EXIT)
	{
		if (game->sprite.down1.t_up == ITEM)
			game->verify.item++;
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y - 1][temp.x].type = PLAYER;
		return (1);
	}
	else if (game->sprite.down1.t_up == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y - 1][temp.x].type = EXIT;
		game->run = 0;
		return (1);
	}
	return (0);
}

int	move_down(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_down != WALL && game->sprite.down1.t_down != EXIT)
	{
		if (game->sprite.down1.t_down == ITEM)
			game->verify.item++;
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + 1][temp.x].type = PLAYER;
		return (1);
	}
	else if (game->sprite.down1.t_down == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + 1][temp.x].type = EXIT;
		game->run = 0;
		return (1);
	}
	return (0);
}

int	move_right(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_right != WALL && game->sprite.down1.t_right != EXIT)
	{
		if (game->sprite.down1.t_right == ITEM)
			game->verify.item++;
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x + 1].type = PLAYER;
		return (1);
	}
	else if (game->sprite.down1.t_right == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x + 1].type = EXIT;
		game->run = 0;
		return (1);
	}
	return (0);
}

int	move_left(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_left != WALL && game->sprite.down1.t_left != EXIT)
	{
		if (game->sprite.down1.t_left == ITEM)
			game->verify.item++;
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x - 1].type = PLAYER;
		return (1);
	}
	else if (game->sprite.down1.t_left == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x - 1].type = EXIT;
		game->run = 0;
		return (1);
	}
	return (0);
}

int	input(int key, t_game *game)
{
	// printf("%d\n", key);
	// printf("collectable %d\nitems %d\nt_up %c\nt_down %c\nt_right %c\nt_left %c\n----------\n", game->verify.collectable, game->verify.item,game->sprite.down1.t_up, game->sprite.down1.t_down, game->sprite.down1.t_right, game->sprite.down1.t_left);
	if (game->run)
	{
		if (key == 119)
		{
			game->lastkey = 'W';
			if (move_up(game))
				printf("Moves: %d\n", ++game->moves);
		}
		if (key == 115)
		{
			game->lastkey = 'S';
			if (move_down(game))
				printf("Moves: %d\n", ++game->moves);
		}
		if (key == 100)
		{
			game->lastkey = 'D';
			if (move_right(game))
				printf("Moves: %d\n", ++game->moves);
		}
		if (key == 97)
		{
			game->lastkey = 'A';
			if (move_left(game))
				printf("Moves: %d\n", ++game->moves);
		}
	}
	if (key == 65307)
		end_game(game);
	return(0);
}
