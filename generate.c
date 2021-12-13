/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:52:34 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 13:20:19 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	*get_tiles(int fd, t_game *game)
{
	t_tile	*tiles;
	int		bytes_read;
	int		j;
	char	c;

	tiles = malloc(sizeof(t_tile) * (game->x_axis + 1));
	bytes_read = read(fd, &c, 1);
	if (!tiles || bytes_read <= 0)
		return (NULL);
	game->verify.px = 0;
	j = 0;
	while (bytes_read > 0 && game->verify.px != game->x_axis)
	{	
		tiles[j].type = validate_tile(&c, game);
		if (tiles[j].type == 0)
		{
			free(tiles);
			return (NULL);
		}
		game->verify.px++;
		j++;
		bytes_read = read(fd, &c, 1);
	}
	tiles[j].type = 0;
	return (tiles);
}

int	map_gen(char *map, t_game *game)
{
	int		fd;
	int		i;
	
	game->tile_map = malloc(sizeof(t_tile *) * (game->y_axis + 1));
	fd = open(map, O_RDONLY);
	if (!game->tile_map || !fd)
		return (0);
	i = 0;
	game->verify.py = 0;
	while (i < game->y_axis)
	{
		game->tile_map[i] = get_tiles(fd, game);
		if (!game->tile_map[i])
		{	
			free_all(game);
			return (0);
		}
		game->verify.py++;
		i++;
	}
	game->tile_map[i] = NULL;
	if (!game->verify.collectable || !game->verify.exit || !game->verify.player)
	{
		free_all(game);
 		return (error("It must have all the necessary items"));
	}
	close(fd);
	return (1);
}
