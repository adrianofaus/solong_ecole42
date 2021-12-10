/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:05:45 by afaustin          #+#    #+#             */
/*   Updated: 2021/10/19 17:05:46 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*new;
	const unsigned char		*origin;
	size_t					i;

	new = (unsigned char *)dest;
	origin = (unsigned char *)src;
	i = 0;
	if (!new && !origin)
		return (NULL);
	if (origin < new)
		while (++i <= n)
			new[n - i] = origin [n - i];
	else
		while (n--)
			*new++ = *origin++;
	return (dest);
}
