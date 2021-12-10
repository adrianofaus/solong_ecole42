/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:08:49 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:08:50 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	n;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst >= size)
		return (size + lsrc);
	n = 0;
	if (size >= (lsrc + ldst + 1))
		n = lsrc;
	else
		n = size - (ldst + 1);
	ft_memcpy(&dst[ldst], src, n);
	dst[ldst + n] = '\0';
	return (lsrc + ldst);
}
