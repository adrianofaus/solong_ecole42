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

void	move_to_up(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_up == ITEM)
		game->verify.item++;
	if (game->sprite.down1.t_up != WALL && game->sprite.down1.t_up != EXIT)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y - 1][temp.x].type = PLAYER;
	}
	else if (game->sprite.down1.t_up == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y - 1][temp.x].type = EXIT;
		game->run = 0;
	}
}

void	move_to_down(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_down == ITEM)
		game->verify.item++;
	if (game->sprite.down1.t_down != WALL && game->sprite.down1.t_down != EXIT)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + 1][temp.x].type = PLAYER;
	}
	else if (game->sprite.down1.t_down == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + 1][temp.x].type = EXIT;
		game->run = 0;
	}
}

void	move_to_right(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_right == ITEM)
		game->verify.item++;
	if (game->sprite.down1.t_right != WALL && game->sprite.down1.t_right != EXIT)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x + 1].type = PLAYER;
	}
	else if (game->sprite.down1.t_right == EXIT && game->verify.collectable == game->verify.item)
	{
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y][temp.x + 1].type = EXIT;
		game->run = 0;
	}
}

void	move_to_left(t_game *game)
{
	t_vector	temp;

	if (game->sprite.down1.t_left == ITEM)
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
		game->tile_map[temp.y][temp.x - 1].type = EXIT;
		game->run = 0;
	}
}

int	input(int key, t_game *game)
{
	printf("%d\n", key);
	printf("collectable %d\nitems %d\nt_up %c\nt_down %c\nt_right %c\nt_left %c\n----------\n", game->verify.collectable, game->verify.item,game->sprite.down1.t_up, game->sprite.down1.t_down, game->sprite.down1.t_right, game->sprite.down1.t_left);
	if (game->run)
	{
		if (key == 119)
		{
			if (game->sprite.down1.t_up == ITEM)
				game->verify.item++;
			move_to_up(game);
		}
		if (key == 115)
		{
			if (game->sprite.down1.t_down == ITEM)
				game->verify.item++;
			move_to_down(game);
		}
		if (key == 100)
		{
			if (game->sprite.down1.t_right == ITEM)
				game->verify.item++;
			move_to_right(game);
		}
		if (key == 97)
		{
			if(game->sprite.down1.t_left == ITEM)
				game->verify.item++;
			move_to_left(game);
		}
	}
	if (key == 65307)
		end_game(game);
	return(0);
}
