/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:43:07 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/16 21:08:43 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!validate_file(argc, argv))
		return (0);
	if (game_init(argv[1], &game))
	{
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, IMG_SIZE * game.x_axis,
				IMG_SIZE * game.y_axis, "so_long");
		mlx_hook(game.win, 2, 1L << 0, input, &game);
		mlx_hook(game.win, 17, 0, &end_game, &game);
		get_images(&game);
		mlx_loop_hook(game.mlx, load_game, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
