/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:48:22 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/14 17:40:03 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	axis_init(char	*map, t_game *game)
{
	char	c;
	int		fd;
	int		bytes_read;

	fd = open(map, O_RDONLY);
	if (!fd)
		return (error("Couldn't open the file"));
	bytes_read = read(fd, &c, 1);
	if (bytes_read ==  -1)
		return (error("Couldn't read the file"));
	game->y_axis = 1;
	while (bytes_read > 0)
	{
		if (c == '\n')
			game->y_axis++;
		if (game->y_axis == 1)
			game->x_axis++;
		bytes_read = read(fd, &c, 1);
	}
	if (c == '\n')
		game->y_axis -= 1;
	close(fd);
	return (1);
}

void	validator_init(t_game *game)
{
	game->verify.px = 0;
	game->verify.py = 1;
	game->verify.exit = 0;
	game->verify.collectable = 0;
	game->verify.player = 0;
	game->verify.item = 0;
}

int	game_init(char *map, t_game *game)
{
	int			is_valid;

	game->x_axis = 0;
	game->y_axis = 0;
	game->run = 1;
	game->lastkey = 0;
	is_valid = 0;
	if (!axis_init(map, game))
		return (is_valid);
	if ((game->x_axis < 3 || game->y_axis < 3) && game->x_axis * game->y_axis < 15)
		return (error("Map must have all items"));
	printf(">: x_axis %d\n", game->x_axis);
	printf(">: y_axis %d\n", game->y_axis);
	validator_init(game);
	is_valid = map_gen(map, game);
	return (is_valid);
}
