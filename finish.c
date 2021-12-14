/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:45:39 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/14 18:33:04 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_null(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_all(t_game *game)
{
	int	i;

	i  = 0;
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
	mlx_destroy_image(game->mlx, game->sprite.exit.img);
	mlx_destroy_image(game->mlx, game->sprite.exit2.img);
}

int	end_game(t_game *game)
{
	free_images(game);
	free_all(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);		
	exit(0);
	return (0);
}