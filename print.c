/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:53:30 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 09:54:06 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*FALTA INCLUIR TRATATIVA DE ERROS DE FD, READ E FREE RECURSIVO
AJUSTAR TRATATIVA DE ERRO QUANDO O MAPA NÃO É RETANGULAR, POIS ESTA DANDO LEAK QUANDO UMA LINHA É MAIOR Q AS
OUTRAS*/

//Função para printar a lista de nodes do primeiro para último item
void	printlist(t_list *head)
{
	t_list	*temporary = head;
	char	*p;
	
	printf("------linked list-------\n");
	while (temporary != NULL)
	{
		p = temporary->content;
		printf(">: %s", p);
		temporary = temporary->next;
	}
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->x_axis && game->y_axis)
	{
		while (game->tile_map[i] != NULL)
		{	
			j = 0;
			while (j < game->x_axis)
			{
				printf("%c", game->tile_map[i][j].type);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}
