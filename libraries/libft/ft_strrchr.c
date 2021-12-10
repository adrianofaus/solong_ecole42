/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:09:36 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:09:37 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;

	b = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			b = ((char *) s);
		s++;
	}
	if (!c)
		return ((char *) s);
	else if (c)
		return (b);
	return (NULL);
}
