/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:09:30 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:09:31 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ls2;

	i = 0;
	ls2 = ft_strlen(s2);
	if (ls2 != 0)
	{
		while (n >= ls2 && s1[i])
		{
			if (s1[i] == *s2)
				if (ft_strncmp(&s1[i], s2, ls2) == 0)
					return ((char *)&s1[i]);
			i++;
			n--;
		}
		return (NULL);
	}
	return ((char *)s1);
}
