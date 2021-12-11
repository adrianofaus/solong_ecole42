/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:28:32 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 12:12:10 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_file(int argc, char **file)
{
	if (argc == 1)
		return (error("Map is missing"));
	else if (!ft_strnstr(&file[1][ft_strlen(file[1]) - 4], ".ber", 4))
		return (error("Map must have .ber extension"));
	if (argc > 2)
		printf("Only the first map will be loaded\n");
	return (1);
}

//MUDAR NOME PARA VALIDATE BORDER
int	is_border(t_validate *position, t_game *game)
{
	if (position->py == 0 || position->py == (game->y_axis - 1) || position->px == 0 || position->px == (game->x_axis - 1))
		return (1);
	return (0);
}

char	validate_tile(char *tile, t_validate *position, t_game *game)
{	
	if (!ft_strchr("01CEP\n", *tile))
		return (error("Invalid char was found, please check the map"));
	if (is_border(position, game) && *tile != '1' && *tile != '\n')
		return (error("It must have walls around the map"));
	if (*tile == 'C')
		position->collectable++;
	//Refatorar este bloco destinado a erro de player para a função map_gen
	if (*tile == 'P')
	{
		position->player++;
		if (position->player > 1)
			return (error("This is a single player game"));
	}
	if (*tile == 'E')
		position->exit++;
	if (position->px == game->x_axis || (*tile == '\n' && (position->px < game->x_axis)))
		return (error("Map must be rectangular"));
	return (*tile);
}

