/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:22:24 by afaustin          #+#    #+#             */
/*   Updated: 2021/12/04 10:24:24 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ESTE BENCHMARK DEVE SER INCLUDO NA MAIN PARA SER USADO

int	main(void)
{
	//INCLUIR NO COMEÇO
	clock_t	begin = clock();
	double	time_spent = 0.0;
	
	/*
	PROGRAMA
	*/
	
	//INCLUIR NO FIM
	clock_t	end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent);
}
