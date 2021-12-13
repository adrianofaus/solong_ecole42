/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:48:22 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 13:17:53 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	axis_init(char *map, t_game *game)
// {
// 	int		bytes_read;
// 	char	buffer[1001];
// 	char	*check;
// 	int		fd;

// 	fd = open(map, O_RDONLY);
// 	ft_bzero(buffer, 1001);
// 	bytes_read = read(fd, buffer, 1000);
// 	while (bytes_read > 0)
// 	{
// 		check = ft_strchr(buffer, '\n');
// 		if (check && !game->y_axis)
// 			game->x_axis += (check - buffer);
// 		else if (!check && !game->y_axis)
// 			game->x_axis += 1000;
// 		while (check)
// 		{
// 			game->y_axis++;
// 			check = ft_strchr(&buffer[1 + check - buffer], '\n');
// 		}
// 		bytes_read = read(fd, buffer, 1000);
// 	}
// 	close(fd);
// }

void	axis_init(char	*map, t_game *game)
{
	char	c;
	int		fd;
	int		bytes_read;

	fd = open(map, O_RDONLY);
	bytes_read = read(fd, &c, 1);
	game->y_axis = 1;
	while (bytes_read > 0)
	{
		if (c == '\n')
			game->y_axis++;
		if (game->y_axis == 1)
			game->x_axis++;
		bytes_read = read(fd, &c, 1);
	}
	close(fd);
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
	axis_init(map, game);
	if ((game->x_axis < 3 || game->y_axis < 3) && game->x_axis * game->y_axis < 15)
		return (error("Map must have all items"));
	printf(">: x_axis %d\n", game->x_axis);
	printf(">: y_axis %d\n", game->y_axis);
	validator_init(game);
	is_valid = map_gen(map, game);
	return (is_valid);
}
