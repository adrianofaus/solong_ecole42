/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:59:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/15 20:22:41 by afaustin         ###   ########.fr       */
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

int	move_to(t_game *game, char dir, int sum_y, int sum_x)
{
	t_vector	temp;

	if (dir != WALL && dir != EXIT)
	{
		if (dir == ITEM)
			game->verify.collectable--;
		temp = game->sprite.down1.current;
		game->tile_map[temp.y][temp.x].type = EMPTY;
		game->tile_map[temp.y + sum_y][temp.x + sum_x].type = PLAYER;
		get_moves(game);
		int i = 0;
		int j = 0;
		while(game->tile_map[i])
		{	
			j = 0;
			while (game->tile_map[i][j].type)
			{
				printf("%c", game->tile_map[i][j].type);
				j++;
			}
			printf("\n");
			i++;
		}
		printf("\n");
		return (1);
	}
	else if (dir == EXIT && game->verify.collectable <= 0)
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
	game->lastkey = key;
	if (game->run)
	{
		if (key == 119)
			move_to(game, game->sprite.down1.t_up, -1, 0);
		else if (key == 115)
			move_to(game, game->sprite.down1.t_down, 1, 0);
		else if (key == 100)
			move_to(game, game->sprite.down1.t_right, 0, 1);
		else if (key == 97)
			move_to(game, game->sprite.down1.t_left, 0, -1);
	}
	if (key == 65307)
		end_game(game);
	return (0);
}
