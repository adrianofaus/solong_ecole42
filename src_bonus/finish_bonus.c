/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:45:39 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/16 21:08:17 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_null(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (game->tile_map[i])
	{
		free_null(game->tile_map[i]);
		i++;
	}
	free_null((game->tile_map));
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.down1.img);
	mlx_destroy_image(game->mlx, game->sprite.left1.img);
	mlx_destroy_image(game->mlx, game->sprite.right1.img);
	mlx_destroy_image(game->mlx, game->sprite.up1.img);
	mlx_destroy_image(game->mlx, game->sprite.tile.img);
	mlx_destroy_image(game->mlx, game->sprite.wall.img);
	mlx_destroy_image(game->mlx, game->sprite.item.img);
	mlx_destroy_image(game->mlx, game->sprite.ext.img);
	mlx_destroy_image(game->mlx, game->sprite.ext2.img);
	mlx_destroy_image(game->mlx, game->sprite.enemy.img);
	mlx_destroy_image(game->mlx, game->sprite.dead.img);
}

int	end_game(t_game *game)
{
	free_images(game);
	free_all(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free_null(game->mlx);
	if (game->count_moves)
		free_null(game->moves);
	exit(0);
	return (0);
}
