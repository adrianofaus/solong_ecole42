/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:05:25 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:05:26 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	find;

	ptr = (unsigned char *) s;
	find = (unsigned char) c;
	while (n)
	{
		if (*ptr == find)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
