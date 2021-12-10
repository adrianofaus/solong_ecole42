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
	
	i = 0;
	while (game->tile_map[i])
	{
		free_null(game->tile_map[i]);
		i++;
	}
	free_null((game->tile_map));
}
