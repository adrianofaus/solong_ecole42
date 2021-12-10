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

t_tile	*get_tiles(int fd, t_game *game, t_validate *position)
{
	t_tile	*tiles;
	int		bytes_read;
	int		j;
	int		flag;
	char	c;

	tiles = malloc(sizeof(t_tile) * (game->x_axis + 1));
	if (!tiles)
		return (NULL);
	bytes_read = read(fd, &c, 1);
	if (bytes_read < 0)
		return (NULL);
	position->px = 0;
	j = 0;
	flag = 0;
	while (bytes_read > 0 && !flag)
	{	
		//REFATORAR ESTA CONDIÇÃO PARA QUE A FUNÇÃO PARE E CONSIGA DAR FREE QUANDO RETORNAR ERRO (SUGESTÃO É REPOSICIONAR O FREE ALL EM TODOS OS LOCAIS DE ERRO)
		//REFATORAR URGENTEEEEEE!!!!! O CÓDIGO PARA QUE A FLAG NÃO SEJA MAIS NECESSÁRIA, INCLUIR UMA MELHOR CONDIÇÃO DE PARADA
		if (j > (game->x_axis) || game->x_axis == 0 || (c == '\n' && j < (game->x_axis)))
		{
			printf("Map must be rectangular\n");
			// tiles[j].type = 0; <- dando invalid writ of size 1 em linhas maiores doq o normal
			return (tiles);
		}
		/*ESTA CONDIÇÃO FOI COLOCADA PARA NÃO DAR LEAK, MAS É UM LIXO DE CÓDIGO,
		CASO EU ARRUME A TRATATIVA DE ERRO PARA M_APAS NÃO RETANGULARES EU POSSO TIRAR ESTA CONDIÇÃO*/
		if (c == '\n')
		{
			flag = 1;
			break;
		}
		tiles[j].type = validate_tile(&c, position, game);
		position->px++;
		j++;
		if (!flag)
			bytes_read = read(fd, &c, 1);
	}
	tiles[j].type = 0;
	return (tiles);
}

//SUBSTITUIR POSITIONS POR I e J?
int	map_gen(char *map, t_game *game, t_validate *position)
{
	int		fd;
	int		i;
	
	game->tile_map = malloc(sizeof(t_tile *) * (game->y_axis + 1));
	if (!game->tile_map)
		return (0);
	fd = open(map, O_RDONLY);
	if (!fd)
		return (0);
	i = 0;
	position->py = 0;
	while (i < game->y_axis)
	{
		game->tile_map[i] = get_tiles(fd, game, position);
		if (!game->tile_map[i])
		{
			game->tile_map[i] = NULL;
			return (0);
		}
		position->py++;
		i++;
	}
	game->tile_map[i] = NULL;
	if (!position->collectable || !position->exit || !position->player)
 		return (error("It must have all the necessary items"));
	// print_map(game);
	close(fd);
	return (1);
}
