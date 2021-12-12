/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:43:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 13:18:00 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!validate_file(argc, argv))
		return (0);
	if (game_init(argv[1], &game))
	{
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, IMG_SIZE * game.x_axis, IMG_SIZE * game.y_axis, "LET's ROCK!");	
		mlx_key_hook(game.win, move_to, &game);
		get_images(&game);
		mlx_loop_hook(game.mlx, load_game, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}