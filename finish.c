/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:45:39 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 13:17:07 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_null(void *ptr)
{
	free(ptr);
	ptr = NULL; //Verificar se eu posso usar a mesma função do GNL
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
	mlx_destroy_image(game->mlx, game->sprite.tile.img);
	mlx_destroy_image(game->mlx, game->sprite.wall.img);
	mlx_destroy_image(game->mlx, game->sprite.item.img);
	mlx_destroy_image(game->mlx, game->sprite.exit.img);
	free(game->sprite.down1.img);
	free(game->sprite.tile.img);
	free(game->sprite.wall.img);
	free(game->sprite.item.img);
	free(game->sprite.exit.img);
}